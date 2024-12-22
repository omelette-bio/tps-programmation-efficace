comment se servir des benchmarks de l'exercice 2 ?

le dossier comporte 4 fichiers importants pour le benchmark:
- mat_mult.c : le programme que l'on souhaite benchmarker
- compiler.sh : le script qui permet de tout compiler
- benchmark.sh : le script qui permet de lancer le benchmark, recolter les donnees d'execution pour l'envoyer au programme python
- export_time_data_for_report : le programme python qui permet de lire les donnees d'execution et de donner un tableau pour les rapports en latex.


comment utiliser benchmark.sh ?

executer le script ./benchmark.sh qui donnera les donnees pour le cas de base, le deroulage de i et la fusion de j.


modifier les listes dans le script benchmark.sh et dans le programme python.

la liste python sert juste a donner les noms aux lignes des benchmarks