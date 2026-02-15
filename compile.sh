#!/usr/bin/bash

action=""
keyboard=0

air40() {
    rm ./.build/ymdk_ymd40_air40_eklofbjorn_air40.hex
    rm ./ymdk_ymd40_air40_eklofbjorn_air40.hex
    rm -r ./.build/*ymdk_ymd40_air40*

    qmk "$action" -kb ymdk/ymd40/air40 -km eklofbjorn_air40
}

planck() {
    rm ./.build/planck_rev6_drop_eklofbjorn.bin
    rm ./planck_rev6_drop_eklofbjorn.bin
    rm -r ./.build/*planck*

    qmk "$action" -kb planck/rev6_drop -km eklofbjorn
}

read -p "What action?
    1) Compile
    2) Flash
    3) Find keymap folders
" action

case $action in

"1" | "compile" | "Compile")
    action="compile"
    ;;

"2" | "flash" | "Flash")
    action="flash"
    ;;

"3" | "find")
    ./findmykeymaps.sh
    exit
    ;;

*)
    echo "Bad action!"
    exit 1
    ;;

esac

read -p "Which keyboard?
    1) Planck
    2) Air40
" keyboard

case $keyboard in

"1" | "planck" | "Planck")
    planck
    ;;

"2" | "air40" | "Air40")
    air40
    ;;

*)
    echo "bad keyboard input!"
    exit 1
    ;;
esac
