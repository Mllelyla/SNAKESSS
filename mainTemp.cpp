


/*


   SSSSSSSSSSSSSSS                                   kkkkkkkk
 SS:::::::::::::::S                                  k::::::k
S:::::SSSSSS::::::S                                  k::::::k
S:::::S     SSSSSSS                                  k::::::k
S:::::S          nnnn  nnnnnnnn      aaaaaaaaaaaaa    k:::::k    kkkkkkk eeeeeeeeeeee
S:::::S          n:::nn::::::::nn    a::::::::::::a   k:::::k   k:::::kee::::::::::::ee
 S::::SSSS       n::::::::::::::nn   aaaaaaaaa:::::a  k:::::k  k:::::ke::::::eeeee:::::ee
  SS::::::SSSSS  nn:::::::::::::::n           a::::a  k:::::k k:::::ke::::::e     e:::::e
	SSS::::::::SS  n:::::nnnn:::::n    aaaaaaa:::::a  k::::::k:::::k e:::::::eeeee::::::e
	   SSSSSS::::S n::::n    n::::n  aa::::::::::::a  k:::::::::::k  e:::::::::::::::::e
			S:::::Sn::::n    n::::n a::::aaaa::::::a  k:::::::::::k  e::::::eeeeeeeeeee
			S:::::Sn::::n    n::::na::::a    a:::::a  k::::::k:::::k e:::::::e
SSSSSSS     S:::::Sn::::n    n::::na::::a    a:::::a k::::::k k:::::ke::::::::e
S::::::SSSSSS:::::Sn::::n    n::::na:::::aaaa::::::a k::::::k  k:::::ke::::::::eeeeeeee
S:::::::::::::::SS n::::n    n::::n a::::::::::aa:::ak::::::k   k:::::kee:::::::::::::e
 SSSSSSSSSSSSSSS   nnnnnn    nnnnnn  aaaaaaaaaa  aaaakkkkkkkk    kkkkkkk eeeeeeeeeeeee


*/



#include "Modifier.h"
#include "Snake.h"
#include "Food.h"
#include "Console.h"
#include "ConsoleKeyFilterUp.h"
#include "PrintImage.h"
#include "StateMachine.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "ElapsedTimer.h"
//faudrait mettre les #include dans un autre fichier
using namespace std;


int main()
{
	ConsoleContext context(70, 60, "B52", 16, 16, L"Consolas");
	Console::defineContext(context);

	StateMachine machine;
	machine.run(Console::getInstance());

	
	return 0;
}

