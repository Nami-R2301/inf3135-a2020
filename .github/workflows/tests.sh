#!/bin/bash

echo -e \\n\*\*\*\*\*\*Tests sans arguments\*\*\*\*\*\*\\n >> fonctionnel.md
echo -e \$ file\.txt \| \.\/tp3\\n >> fonctionnel.md
cat file.txt | ./tp3 >> fonctionnel.md
echo -e \\n\*\*\*\*\*\*Tests avec arguments\*\*\*\*\*\*\\n >> fonctionnel.md
echo -e \$ file\.txt \| \.\/tp3 -i -s -d\\n >> fonctionnel.md
cat file.txt | ./tp3 -i -s -d >> fonctionnel.md
echo -e \\n\$ file\.txt \| \.\/tp3 -t -s -d -i\\n >> fonctionnel.md
cat file.txt | ./tp3 -t -s -d -i >> fonctionnel.md
echo -e \\n\$ file2\.txt \| \.\/tp3 --t --s --b --d\\n >> fonctionnel.md
cat file2.txt | ./tp3 --t --s --b --d >> fonctionnel.md
echo -e \\n\$ file2\.txt \| \.\/tp3 -t\\n >> fonctionnel.md
cat file2.txt | ./tp3 -t >> fonctionnel.md
echo -e \\n\*\*\*\*\*\*Tests avec STDIN vide\*\*\*\*\*\*\\n >> fonctionnel.md
echo -e \$ \.\/tp3 -t\\n >> fonctionnel.md
./tp3 -t >> fonctionnel.md
echo -e \\n\$ \.\/tp3 -i -s -d\\n >> fonctionnel.md
./tp3 -i -s -d >> fonctionnel.md
echo -e \\n\$ \.\/tp3\\n >> fonctionnel.md
./tp3 >> fonctionnel.md
