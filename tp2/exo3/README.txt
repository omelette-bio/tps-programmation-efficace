comment se servir des benchmarks de l'exercice 3 ?

le dossier comporte 4 fichiers importants pour le benchmark:
- mat_mult.c : le programme que l'on souhaite benchmarker
- compiler.sh : le script qui permet de tout compiler
- benchmark.sh : le script qui permet de lancer le benchmark, recolter les donnees d'execution pour l'envoyer au programme python
- export_time_data_for_report : le programme python qui permet de lire les donnees d'execution et de donner un tableau pour les rapports en latex.


comment utiliser benchmark.sh ?

dans le script il ya 2 listes differentes, elles permettent de benchmarker 2 donnees differentes:
1. comment l'ordre des boucles de base se compare aux autres
2. comment l'ordre des boucles de base se compare a l'option -floop-interchange


modifier les listes dans le script benchmark.sh et dans le programme python.

la liste python sert juste a donner les noms aux lignes des benchmarks