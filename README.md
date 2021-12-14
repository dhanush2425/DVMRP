Distance Vector Routing Implementation Using C
I have 3 files which are Host,Router and Controller.

Compile all 3 files using:

gcc host.c -o host
gcc router.c -o router
gcc controller.c -o controller

Once compiled, create a bash file like scenario.sh and all the command:
rm -rf LAN* HOUT* HIN* to remove old previos files

Finally run the scenario.sh file using bash command.

Scenario.sh file example:

 rm -rf LAN* HOUT* HIN*
./host 0 0 sender 50 20&
./host 1 1 receiver &
./router 0 0 1 &
./router 1 1 2 &
./router 2 2 3 &
./router 3 3 0 &
./controller host 0 1 router 0 1 2 3 lan 0 1 2 3&
                                                  
