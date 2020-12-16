#!/bin/bash

echo -e \\n\*\*\*\*\*\*Tests sans arguments\*\*\*\*\*\*\\n >> ../../fonctionnel.md
echo -e \$ Fichier-tests-f\.txt \| \.\/tp3\\n >> ../../fonctionnel.md
cat .github/workflows/Fichier-tests-f.txt | bash tp3 >> ../../fonctionnel.md
echo -e \\n\*\*\*\*\*\*Tests avec arguments\*\*\*\*\*\*\\n >> ../../fonctionnel.md
echo -e \$ Fichier-tests-f\.txt \| \.\/tp3 -i -s -d\\n >> ../../fonctionnel.md
cat .github/workflows/Fichier-tests-f.txt | bash tp3 -i -s -d >> ../../fonctionnel.md
echo -e \\n\$ Fichier-tests-f\.txt \| \.\/tp3 -t -s -d -i\\n >> ../../fonctionnel.md
cat .github/workflows/Fichier-tests-f.txt | bash tp3 -t -s -d -i >> ../../fonctionnel.md
echo -e \\n\$ Fichier-tests-f\.txt \| \.\/tp3 --t --s --b --d\\n >> ../../fonctionnel.md
cat .github/workflows/Fichier-tests-f.txt | bash tp3 --t --s --b --d >> ../../fonctionnel.md
echo -e \\n\$ Fichier-tests-f\.txt \| \.\/tp3 -t\\n >> ../../fonctionnel.md
cat .github/workflows/Fichier-tests-f.txt | bash tp3 -t >> ../../fonctionnel.md
echo -e \\n\*\*\*\*\*\*Tests avec STDIN vide\*\*\*\*\*\*\\n >> ../../fonctionnel.md
echo -e \$ \.\/tp3 -t\\n >> ../../fonctionnel.md
bash tp3 -t >> ../../fonctionnel.md
echo -e \\n\$ \.\/tp3 -i -s -d\\n >> ../../fonctionnel.md
bash tp3 -i -s -d >> ../../fonctionnel.md
echo -e \\n\$ \.\/tp3\\n >> ../../fonctionnel.md
bash tp3 >> ../../fonctionnel.md
