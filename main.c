#include <stdio.h>
#include "area.h"
#include "commandes.h"

int main()
{
   Area *area = create_area(20, 20);
   int exit = 0;
   while(exit == 0){
       Command *cmd = create_commande();
       read_from_stdin(cmd);
       exit = read_exec_command(cmd, area);
   }
    return 0;
}
