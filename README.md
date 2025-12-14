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
  
| Quantité | Principaux composants | Lien | Coût |
|  :---:  | :---:  | :---:  | :---:  | 
| 1 | `Microcontrôleur ESP32` | [ ESP32 ](https://www.amazon.fr/ESP32-d%C3%A9veloppement-RUIZHI-ESP32-WROOM-32D-CH340/dp/B0CLCQ64W2/ref=sr_1_15?dib=eyJ2IjoiMSJ9.QkMsoOlqgs8RuoVI8WERCb88GIqQakaAbT6RtnoQgB1jQQjYm6aUoN7WAboM9_reazxVls9eF5Xsf6Xu-yYuCjr54fjB1k59R_R7qKMvPSOd4gQ_iME_YDpNDP8zNS4emgeex_hx_lRMRDyXQk06-jKeenPt7fDKbVD2rwoOIOipMYaooHAi7y7GodstGxDqWKoP_uYAsmtS_GieLEViv2PL5HvlpBZlUVcbvJT0AvfVuHD4N1V4WqUXxvgFLmgznKKr6V29h5HiIjl3N-kINl0NRWoDKmOSwc1WMHgJVMY.3SJ5NKNXxiw6LEeFS_nbdXgEE3QUpI3YbZFA4LGAhPc&dib_tag=se&keywords=esp32&qid=1765730383&sr=8-15) | 7.99€ |
| 1 | `Capteur de Tension AC Grove` | [ AC Grove 101991032 ](https://www.gotronic.fr/art-capteur-de-tension-ac-grove-101991032-36282.htm?srsltid=AfmBOorIeBoYQaFvXzIaMeY5EBjBGz3wjRMceioXvRc0mivrkZl4O75Y) | 7.99€ |
| 1 | `Pince ampèremétrique YHDC` | [ YHDC 30A 50A 100A SCT013 ](https://www.aliexpress.com/p/tesla-landing/index.html?scenario=c_ppc_item_bridge&productId=4000398770406&_immersiveMode=true&withMainCard=true&src=google&aff_platform=true&isdl=y&src=google&albch=shopping&acnt=248-630-5778&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=UneMJZVf&gclsrc=aw.ds&&albagn=888888&&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=fr4000398770406&ds_e_product_merchant_id=107732565&ds_e_product_country=FR&ds_e_product_language=fr&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=19579670800&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gad_campaignid=19571495907&gbraid=0AAAAACWaBweT5nfEPefp0p4L7a0ewHZj-&gclid=CjwKCAiA3fnJBhAgEiwAyqmY5ZMNJ4HAQ6Bgdy_G2vnzymxvmvX_wthq_G5ykDxtgkoOa5uzqDALmhoChTsQAvD_BwE) | 7.99€ |
| 1 | `Conditionneur : Pont diviseur de tension + condensateur` | [Résistances 10kΩ ](https://fr.aliexpress.com/item/1005008677253969.html?spm=a2g0o.productlist.main.2.31c450a6b1YP9h&aem_p4p_detail=202512140854152270770232296280002568967&algo_pvid=b333e026-252d-4c7c-900c-f5a2d760f8c7&algo_exp_id=b333e026-252d-4c7c-900c-f5a2d760f8c7-1&pdp_ext_f=%7B%22order%22%3A%22990%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%211.72%210.99%21%21%2113.87%217.95%21%4021038df617657312553442305e40b5%2112000046202387972%21sea%21FR%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3A8703b829%3Bm03_new_user%3A-29895%3BpisId%3A5000000187633565&curPageLogUid=hQbhohYWZJr8&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005008677253969%7C_p_origin_prod%3A&search_p4p_id=202512140854152270770232296280002568967_1&_gl=1*zscu0u*_gcl_aw*R0NMLjE3NjU3MzEyNTkuQ2p3S0NBaUEzZm5KQmhBZ0Vpd0F5cW1ZNVpCaDRyQi1oc3VmWG9FSTlNV2JmZ3k3cklZdWNMbEJ4NzhnZkIyZG1Ga0QzT1hDMWdRRzF4b0NQY1lRQXZEX0J3RQ..*_gcl_dc*R0NMLjE3NjU3MzEyNTkuQ2p3S0NBaUEzZm5KQmhBZ0Vpd0F5cW1ZNVpCaDRyQi1oc3VmWG9FSTlNV2JmZ3k3cklZdWNMbEJ4NzhnZkIyZG1Ga0QzT1hDMWdRRzF4b0NQY1lRQXZEX0J3RQ..*_gcl_au*MjI1NTM5NjU5LjE3NjU3MzA4NDQ.*_ga*MTg0OTY3NzIxMC4xNzY1NzMwODQ0*_ga_VED1YSGNC7*czE3NjU3MzA4NDMkbzEkZzEkdDE3NjU3MzEyNTgkajYwJGwwJGgw) + [Condensateur 10μF ](https://fr.aliexpress.com/item/1005009888050325.html?spm=a2g0o.productlist.main.1.1bbe5cdejhRTxS&algo_pvid=73e3a118-4435-461d-8bc8-912ad42fb475&algo_exp_id=73e3a118-4435-461d-8bc8-912ad42fb475-0&pdp_ext_f=%7B%22order%22%3A%22339%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%213.42%211.89%21%21%2127.64%2115.26%21%402102f22c17657313190714690ebef0%2112000050484837788%21sea%21FR%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3A8703b829%3Bm03_new_user%3A-29895%3BpisId%3A5000000187633564&curPageLogUid=WlklvPsnhork&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005009888050325%7C_p_origin_prod%3A) | 7.99€ |

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
