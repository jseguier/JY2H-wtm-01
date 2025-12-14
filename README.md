# ⚡ JY2H-wtm-01

# Introduction

Dans le cadre d'un **projet en Instrumentation Avancée** au département Mesures Physiques de Marseille, nous avons réalisé en **quadrinôme** un prototype IoT de **capteur connecté de mesure de puissance** dont l'objectif était de **mesurer** les puissances <ins>active</ins>, <ins>réactive</ins> et <ins>apparente</ins>.

Pour fonctionner, le prototype s'appuie sur **2** capteurs : une **pince ampèremétrique** couplée à un **conditionneur**, ainsi qu'un **capteur de tension**. L'ensemble est connecté à un **microcontrôleur** type **ESP32** qui assure le **traitement** des données. La **visualisation** des valeurs obtenues est assurée par une interface IoT simple **Node-RED**.

# Fonctionnalités

- Mesure de la tension efficace (en V)
- Mesure du courant efficace (en A)
- Mesure du déphasage (en DEG)
- Mesure des puissances active, réactive, apparente (en W, VAR et VA)

# Matériels utilisés

<p align="center">
  <img width="800" height="500" alt="branchement-wtm" src="https://github.com/user-attachments/assets/00a1fcaf-851e-47c7-b55a-417c0d324cce" />
  <br>
  <em>Figure 2 – </em>
  <br>
  <br>
</p>



<div align="center">
  
| Identification | Quantité | Principaux composants | 
|  :---:  |  :---:  | :---:  | 
| 1 | 1 | `Microcontrôleur ESP32` | 
| 2 | 1 | `Capteur de Tension AC Grove` | 
| 3 | 1 | `Pince ampèremétrique YHDJ` | 
| 4 | 1 | `Conditionneur : Pont diviseur de tension + condensateur` | 

</div>
<br>
<br>
