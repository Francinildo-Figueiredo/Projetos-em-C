#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <locale>

#include "Conversor.h"

int main()
{
	setlocale( LC_ALL, "portuguese" );
	
	Conversor conversor;
	int menu = 1, escolha, x;
		
	while( menu != 0 )
	{
		cout << "Este programa trabalha com convers�es da base decimal para octal e hexadecimal, p�rem cada\n"
			<< "uma tem seu limite de convers�o, devido ao limite m�ximo das vari�veis do tipo unsigned long long,\n"
			<< "que s� podem chegar ao valor em decimal de 18.446.744.073.709.551.615.\n\n"
			<< "1 - Decimal para bin�rio\n"
			<< "2 - Bin�rio para decimal\n"
			<< "3 - Decimal para octal\n"
			<< "4 - Octal para decimal\n"
			<< "5 - Decimal para hexadecimal\n"
			<< "6 - Hexadecimal para decimal\n"
			<< "0 - Sair\n"
			<< "\nEscolha uma op��o de convers�o, ou 0 para sair --> ";
		
		cin >> escolha;
		x = 1;
		system("cls");
		
		while( x != 0 )
		{
			switch( escolha )
			{
				case 1:
					{
						cout << "Este conversor trabalha com decimais de 0 at� 2^16 - 1.\n"
							<< "Ou seja, uma faixa de 0 - 65535.\n";
						unsigned long long number;
						cout << "\nDigite um n�mero em decimal: ";
						if ( cin >> number )
						{
							system("cls");
							if ( number >= 0 && number <= 65535 )
							{
								conversor.setDecimal( number );
								
								cout << "\n-=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n"
									<< "\n  " << conversor.getDecimal() << " (decimal) ---> " << conversor.converteDecimalBinario()
									<< " (bin�rio)\n"
									<< "\n-=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n" << endl;
								x = 0;
							}
							else
							{
								system("cls");
								cout << "O decimal digitado n�o esta na faixa de 0 - 65535!\n" << endl;
								x = 0;
							}
						}
						else
						{
							system("cls");
							cout << "N�o s�o permitidos caracteres\n" << endl;
							x = 0;
							menu = 0; 
						}
						
						system("pause");
						system("cls");
						break;
					}
				case 2:
					{
						cout << "Esta convers�o trabalha com bin�rios de at� 16 bits.\n"
							<< "Ou seja, uma faixa de 0000000000000000 - 1111111111111111.\n";
						long long binary;
						cout << "\nDigite um n�mero em bin�rio: ";
						if ( cin >> binary )
						{
							system("cls");
							if ( conversor.setBinario( binary ) )
							{
								cout << "\n-=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n"
									<< "\n  " << binary << " (bin�rio) --> " << conversor.converteBinarioDecimal()
									<< " (decimal)\n"
									<< "\n-=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n" << endl;
								x = 0;
							}
							else
								x = 0;
						}
						else
						{
							system("cls");
							cout << "Ocorreu um estouro!\n" << endl;
							x = 0;
							menu = 0;
						}
						
						system("pause");
						system("cls");
						break;
					}
				case 3:
					{
						cout << "Este conversor trabalha com decimais de 0 at� 8^21 - 1.\n"
							<< "Ou seja, uma faixa de 0 - 9.223.372.036.854.775.808.\n";
							
						unsigned long long number;
						cout << "\nDigite um n�mero decimal: ";
						
						if ( cin >> number )
						{
							system("cls");
							conversor.setDecimal( number );				
							cout << "\n-=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n"
								<< "\n  " << conversor.getDecimal() << " (decimal) --> "
								<<  conversor.converteDecimalOctal() << " (Octal)\n"
								<< "\n-=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n" << endl;
							x = 0;	
						}
						else
						{
							system("cls");
							cout << "Ocorreu um estouro!\n\n";
							x = 0;
							menu = 0; 
						}
						
						system("pause");
						system("cls");
						break;
					}
				case 4:
					{
						cout << "Este conversor trabalha com octais de at� 21 d�gitos.\n"
						     << "Ou seja, uma faixa de 0 - 777777777777777777777.\n";
						
						string octal;
						cin.ignore();
						cout << "\nDigite um n�mero Octal: ";
						getline(cin, octal);
						
						system("cls");
						if ( conversor.setOctal( octal ) )
						{
							cout << "-=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n"
								<< "\n  " << conversor.getOctal() << " (Octal) --> "
								<<  conversor.converteOctalDecimal() << " (decimal)\n"
								<< "\n-=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n" << endl;
							x = 0;
						}
						else
							x = 0;
						
						system("pause");
						system("cls");
						break;
					}
				case 5:
					{
						cout << "Este conversor trabalha com decimais de 0 at� 16^16 - 1.\n"
							<< "Ou seja, uma faixa de 0 - 18.446.744.073.709.551.616.\n";
						
						unsigned long long number;
						cout << "\nDigite um n�mero decimal: ";
						
						if ( cin >> number )
						{
							system("cls");
							conversor.setDecimal( number );				
							cout << "\n-=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n"
								<< "\n  " << conversor.getDecimal() << " (decimal) --> "
								<<  conversor.converteDecimalHexa() << " (hexadecimal)\n"
								<< "\n-=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n" << endl;
							x = 0;	
						}
						else
						{
							system("cls");
							cout << "Ocorreu um estouro!\n\n";
							x = 0;
							menu = 0; 
						}
						
						system("pause");
						system("cls");
						break;
					}
				case 6:
					{
						cout << "Este conversor trabalha com hexadecimais de at� 16 d�gitos.\n"
							<< "Ou seja, uma faixa de 0 - FFFFFFFFFFFFFFFF.\n";
						
						string hexd;
						cin.ignore();
						cout << "\nDigite um n�mero hexadecimal: ";
						getline(cin, hexd);
						
						system("cls");
						if ( conversor.setHexadecimal( hexd ) )
						{
							cout << "-=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n"
								<< "\n  " << conversor.getHexadecimal() << " (hexadecimal) --> "
								<<  conversor.converteHexaDecimal() << " (decimal)\n"
								<< "\n-=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n" << endl;
							x = 0;
						}
						else
							x = 0;
						
						system("pause");
						system("cls");
						break;
					}
				case 0:
					{
						cout << "Saindo..." << endl;
						x = 0;
						menu = 0;
						break;
					}
				default:
					{
						x = 0;
						cout << "Op��o incorreta!\n" << endl;
						break;
					}
			}
		}
	}
	
	return 0;
}
