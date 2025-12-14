# ⚡ JY2H-wtm-01

# Introduction

Dans le cadre d'un **projet en Instrumentation Avancée** au département Mesures Physiques de Marseille, nous avons réalisé en **quadrinôme** un prototype IoT de **capteur connecté de mesure de puissance** dont l'objectif était de **mesurer** les puissances <ins>active</ins>, <ins>réactive</ins> et <ins>apparente</ins>.

Pour fonctionner, le prototype s'appuie sur **2** capteurs : une **pince ampèremétrique** couplée à un **conditionneur**, ainsi qu'un **capteur de tension**. L'ensemble est connecté à un **microcontrôleur** type **ESP32** qui assure le **traitement** des données. La **visualisation** des valeurs obtenues est assurée par une interface IoT simple **Node-RED**.

# Fonctionnalités

- Mesure de la tension efficace (en V)
- Mesure du courant efficace (en A)
