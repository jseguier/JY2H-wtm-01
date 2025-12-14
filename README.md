# ⚡ JY2H-wtm-01

# Introduction

Dans le cadre d'un **projet en Instrumentation Avancée** au département Mesures Physiques de Marseille, nous avons réalisé en **quadrinôme** un prototype IoT de **capteur connecté de mesure de puissance** dont l'objectif était de **mesurer** les puissances <ins>active</ins>, <ins>réactive</ins> et <ins>apparente</ins>.

Pour fonctionner, le prototype s'appuie sur **2** capteurs : une **pince ampèremétrique** couplée à un **conditionneur**, ainsi qu'un **capteur de tension**. L'ensemble est connecté à un **microcontrôleur** type **ESP32** qui assure le **traitement** des données. La **visualisation** des valeurs obtenues est assurée par une interface IoT simple **Node-RED**.

# Fonctionnalités

- Acquisition en temps réel
- Mesure de la tension efficace (en V)
- Mesure du courant efficace (en A)
- Mesure du déphasage (en DEG)
- Mesure des puissances active, réactive, apparente (en W, VAR et VA)

# Matériels utilisés
  
| Quantité | Principaux composants | Lien |
|  :---:  | :---:  | :---:  | 
| 1 | `Microcontrôleur ESP32` | [https://www.amazon.fr/ESP32-d%C3%A9veloppement-RUIZHI-ESP32-WROOM-32D-CH340/dp/B0CLCQ64W2/ref=sr_1_15?dib=eyJ2IjoiMSJ9.QkMsoOlqgs8RuoVI8WERCb88GIqQakaAbT6RtnoQgB1jQQjYm6aUoN7WAboM9_reazxVls9eF5Xsf6Xu-yYuCjr54fjB1k59R_R7qKMvPSOd4gQ_iME_YDpNDP8zNS4emgeex_hx_lRMRDyXQk06-jKeenPt7fDKbVD2rwoOIOipMYaooHAi7y7GodstGxDqWKoP_uYAsmtS_GieLEViv2PL5HvlpBZlUVcbvJT0AvfVuHD4N1V4WqUXxvgFLmgznKKr6V29h5HiIjl3N-kINl0NRWoDKmOSwc1WMHgJVMY.3SJ5NKNXxiw6LEeFS_nbdXgEE3QUpI3YbZFA4LGAhPc&dib_tag=se&keywords=esp32&qid=1765730383&sr=8-15](test) |
| 1 | `Capteur de Tension AC Grove` | 
| 1 | `Pince ampèremétrique YHDJ` | 
| 1 | `Conditionneur : Pont diviseur de tension + condensateur` | 

</div>
<br>
<br>

# Logiciels utilisés

<img width="2868" height="600" alt="image" src="https://github.com/user-attachments/assets/eb8bf9ab-1b39-4b9f-b141-e1a9c397d93b" />


<br>
<br>


<div align="center">

| Logiciels |  Description | 
|  :---:  |  :---:  |
| `Visual Studio Code &  PlatformIO` | Éditeur de code source développé par Microsoft + environnement de développement IoT PlatformIO | 
| `Mosquitto (protocole MQTT)` | Brocker open-source utilisant le protocole MQTT : collecte les données des capteurs | 
| `Node-RED (interface utilisateur)` | Outil de développement " low-code" : programmation visuelle basée sur des flux | 

</div>

<br>
<br>

# Logigrammes
