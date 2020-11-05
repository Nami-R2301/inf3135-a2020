#!/bin/bash
#Programme qui lie la sortie standard et l'interprete comme une entree standard en affichant seulement les tests qui ont passes.

STDIN=$(grep -e FAILED -)

echo "


$STDIN


"
