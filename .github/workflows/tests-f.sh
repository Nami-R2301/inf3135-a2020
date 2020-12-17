#!/bin/bash

echo -e \!\[test-f\]\(https\:\/\/github.com\/Nami-R2301\/inf3135-a2020\/workflows\/test-f\/badge\.svg\?branch\=tp3\)\\n\\n > fonctionnel.md 
echo -e \\n\#\# Tests fonctionnels pour le TP3 à jour \($(TZ=America/New_York date)\): \\n >> fonctionnel.md
echo -e \\n\\n\#\#\# Contenu de\/des Fichier\(s\) testé\(s\) :\\n >> fonctionnel.md
echo -e \`\`\`\\n >> fonctionnel.md
echo -e \$ cat \.github\/workflows\/Fichier-tests-f\.txt\\n >> fonctionnel.md 
cat .github/workflows/Fichier-tests-f.txt >> fonctionnel.md 
echo -e \\n\`\`\`\\n >> fonctionnel.md
echo -e \\n\#\#\# Tests sans arguments :\\n >> fonctionnel.md
echo -e \`\`\`\\n >> fonctionnel.md
echo -e \$ cat \.github\/workflows\/Fichier-tests-f\.txt \| \.\/tp3\\n >> fonctionnel.md
cat .github/workflows/Fichier-tests-f.txt | ./tp3 >> fonctionnel.md
echo -e \\n\`\`\`\\n >> fonctionnel.md
echo -e \\n\#\#\# Tests avec arguments :\\n >> fonctionnel.md
echo -e \\n\`\`\`\\n >> fonctionnel.md
echo -e \$ cat \.github\/workflows\/Fichier-tests-f\.txt \| \.\/tp3 -i -s -d\\n >> fonctionnel.md
cat .github/workflows/Fichier-tests-f.txt | ./tp3 -i -s -d >> fonctionnel.md
echo -e \\n\$ cat \.github\/workflows\/Fichier-tests-f\.txt \| \.\/tp3 -t -s -d -i\\n >> fonctionnel.md
cat .github/workflows/Fichier-tests-f.txt | ./tp3 -t -s -d -i >> fonctionnel.md
echo -e \\n\$ cat \.github\/workflows\/Fichier-tests-f\.txt \| \.\/tp3 --t --s --b --d\\n >> fonctionnel.md
cat .github/workflows/Fichier-tests-f.txt | ./tp3 --t --s --b --d >> fonctionnel.md
echo -e \\n\$ cat \.github\/workflows\/Fichier-tests-f\.txt \| \.\/tp3 -t\\n >> fonctionnel.md
cat .github/workflows/Fichier-tests-f.txt | ./tp3 -t >> fonctionnel.md
echo -e \\n\`\`\`\\n >> fonctionnel.md
echo -e \\n\#\#\# Tests avec STDIN vide :\\n >> fonctionnel.md
echo -e \\n\`\`\`\\n >> fonctionnel.md
echo -e \$ \.\/tp3 -t\\n >> fonctionnel.md
./tp3 -t >> fonctionnel.md
echo -e \\n\$ \.\/tp3 -i -s -d\\n >> fonctionnel.md
./tp3 -i -s -d >> fonctionnel.md
echo -e \\n\$ \.\/tp3\\n >> fonctionnel.md
./tp3 >> fonctionnel.md
echo -e \\n\`\`\`\\n >> fonctionnel.md
echo -e \\n\#\#\# Tests avec valgrind\\n >> fonctionnel.md
echo -e \\n\`\`\`\\n >> fonctionnel.md
echo -e \\n\$ cat \.github\/workflows\/Fichier-tests-f\.txt \| valgrind \.\/tp3 -i -s -d\\n >> fonctionnel.md
cat .github/workflows/Fichier-tests-f.txt | valgrind ./tp3 -i -s -d &>> fonctionnel.md
echo -e \\n\$ \.\/tp3 -t -i -dd -sfg -sffgg\\n >> fonctionnel.md
valgrind ./tp3 -t -i -dd -sfg -sffgg &>> fonctionnel.md
echo -e \\n\`\`\` >> fonctionnel.md
