#include <Arduino.h>
#include "PubSubClient.h"
#include "WiFi.h"
#include "esp_wpa2.h"
#include "math.h"




const int N = 40;                 // Nombre de mesures
const float temps = 500-167;      // Temps entre deux mesures (en µs), 167µs = temps de calcul

int f = 50;                 // Fréquence du secteur (en Hz)
float Uac[N];               // Tension alternative mesurée
float Iac[N];               // Courant alternatif mesuré
float t[N];                 // Instants correspondants aux mesures (en ms)
float Su = 0;               // Somme des tensions mesurées
float Umoy = 0;             // Valeur moyenne de la tension mesurée (offset)
float Si = 0;               // Somme des courants mesurés
float Imoy = 0;             // Valeur moyenne du courant mesuré (offset)

float Umax = 0;             // Tension maximale mesurée sur la période T = 1/f
long tU = 0;                // Instant correspondant à la mesure de Umax
float Imax = 0;             // Courant maximal mesuré sur la période T = 1/f
long tI = 0;                // Instant correspondant à la mesure de Imax
float phi_rad = 0;          // Déphasage entre la tension et le courant (en rad)
float phi_deg = 0;          // Déphasage entre la tension et le courant (en °)

float Urms = 0;             // Tension efficace (en V)
float Irms = 0;             // Courant efficace (en A)
float P = 0;                // Puissance active (en W)
float Q = 0;                // Puissance réactive (en var)
float S = 0;                // Puissance apparente (en VA)

int i = 0;                  // Compteur i
int j = 0;                  // Compteur j
int k = 0;                  // Compteur k
int l = 0;                  // Compteur l
int m = 0;                  // Compteur m



// Paramètres MQTT Broker
const char *mqtt_broker = ""; // Identifiant du broker (Adresse IP)
const char *topic1 = "Urms"; // Nom du topic sur lequel les données seront envoyés.
const char *topic2 = "Irms";
const char *topic3 = "Phi";
const char *topic4 = "P";
const char *topic5 = "Q";
const char *topic6 = "S";

const char *mqtt_username = ""; // Identifiant WPA2
const char *mqtt_password = ""; // Mdp WPA2
const int mqtt_port = 1883; // Port : 1883 dans le cas d'une liaison non sécurisée et 8883 dans le cas d'une liaison cryptée



WiFiClient espClient;
PubSubClient client(espClient);




// Paramètres EDUROAM
#define EAP_IDENTITY "" // mail
#define EAP_PASSWORD "" // MDP
#define EAP_USERNAME "" // mail
const char* ssid = "eduroam"; // eduroam SSID


// Fonction réception du message MQTT
void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Le message a été envoyé sur le topic : ");
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char) payload[i]);
  }
  Serial.println();
  Serial.println("-----------------------");
}




void setup() {
  Serial.begin(115200);


    // Connexion au réseau EDUROAM
    WiFi.disconnect(true);
    WiFi.begin(ssid, WPA2_AUTH_PEAP, EAP_IDENTITY, EAP_USERNAME, EAP_PASSWORD);
  
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(F("."));
    }
    Serial.println("");
    Serial.println(F("L'ESP32 est connecté au WiFi !"));
  

    // Connexion au broker MQTT  
      client.setServer(mqtt_broker, mqtt_port);
      client.setCallback(callback);

      while (!client.connected()) {
        String client_id = "esp32-client-";
        client_id += String(WiFi.macAddress());
        Serial.printf("La chaîne de mesure %s se connecte au broker MQTT", client_id.c_str());
    
        if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
          Serial.println("La chaîne de mesure est connectée au broker.");
        } else {
          Serial.print("La chaîne de mesure n'a pas réussi à se connecter ... ");
          Serial.print(client.state());
          delay(2000);
        }
      }
}



void loop() {



    // Acquisition des données (temps, tension, courant)
      while (i < N)
      {
        t[i] = micros();
        Uac[i] = analogRead(36);
        Iac[i] = analogRead(39);
        delayMicroseconds(temps);
        i++;
      }


    // Traitement des mesures une fois l'acquisition achevée
      if (i == N)
      {
        // Détermination des offsets
        for( j = 0; j < N; j++) 
        {
          Su = Su + Uac[j];
          Si = Si + Iac[j];
        }
        Umoy = Su/N;
        Imoy = Si/N;

        // Correction de l'offset et conversion des valeurs brutes
        for( k=0; k < N; k++) 
        {
          client.publish(topic11, String(Uac[k]).c_str());
          client.subscribe(topic11);
          client.publish(topic12, String(t[k]).c_str());
          client.subscribe(topic12);
          Uac[k] = (Uac[k] - Umoy) * 1278/10000 + 3342/10000;
          Iac[k] = (Iac[k] - Imoy) * 166/10000 - 1058/10000;
        }

        // Recherche des maxima
        for ( l = 0; l < N; l++) 
        {
          Umax = max(Umax, Uac[l]);
          Imax = max(Imax, Iac[l]);
        }

        // Recherche des instants associés aux maxima
        for ( m = 0; m < N; m++){ 
          if (Uac[m] == Umax)
          {
            tU = t[m];
          }
          if (Iac[m] == Imax)
          {
            tI = t[m];
          }
        }
 

    // Calculs des grandeurs
    phi_rad = 2*M_PI*f*abs(tU-tI)/1000000;
    phi_deg = 360*f*abs(tU-tI)/1000000;

    Urms = Umax/sqrt(2);
    Irms = Imax/sqrt(2);

    P = Urms*Irms*abs(cos(phi_rad));
    Q = Urms*Irms*abs(sin(phi_rad));
    S = Urms*Irms;




    // Publication des données sur des topics
    client.publish(topic1, String(Urms).c_str());
    client.subscribe(topic1);
    client.publish(topic2, String(Irms).c_str());
    client.subscribe(topic2);
    client.publish(topic3, String(phi_deg).c_str());
    client.subscribe(topic3);
    client.publish(topic4, String(P).c_str());
    client.subscribe(topic4);
    client.publish(topic5, String(Q).c_str());
    client.subscribe(topic5);
    client.publish(topic6, String(S).c_str());
    client.subscribe(topic6);


 
    i++; // Comme i = N + 1, la boucle s'arrête.
  }
}
