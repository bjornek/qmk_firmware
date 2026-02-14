#!/bin/bash

rm ./.build/planck_rev6_drop_eklofbjorn.bin
rm ./planck_rev6_drop_eklofbjorn.bin
rm -r ./.build/*planck*

qmk $1 -kb planck/rev6_drop -km eklofbjorn
