#!/bin/bash

echo -e \!\[test-c\]\(https\:\/\/github.com\/Nami-R2301\/inf3135-a2020\/workflows\/test-c\/badge\.svg\?branch\=tp3\)\\n > compilation.md
echo -e \#\# Tests de compilation pour le TP3 à jour \($(TZ=America/New_York date\) :\\n >> compilation.md
echo -e \`\`\`\\n >> compilation.md
TZ=America/New_York date >> compilation.md
echo -e \\n >> compilation.md
make &>> compilation.md
echo -e \\n\`\`\` >> compilation.md
