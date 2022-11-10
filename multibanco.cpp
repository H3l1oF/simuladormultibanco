// Simulador MultiBanco

#include <iostream>


using namespace std;

int main() {
  float s=100, a;
  int o;
  do {
    cout << "\033[2J\033[1;1H"; // este cout faz o clear ao screen
    cout << "     Menu\n";
    cout << "1- Consultar saldo\n";
    cout << "2- Levantar dinheiro\n";
    cout << "3- Depositar dinheiro\n";
    cout << "4- Sair\n";
    cout << "\nEscolha uma Opcao:";
    cin >> o;
    switch (o) {
      case 1:
        cout << "\033[2J\033[1;1H";
        cout << "\nO seu saldo e' de: " << s << "e\n";
        cin.ignore();
        cin.get();
        break;
      case 2:
        do {
          cout << "\033[2J\033[1;1H";
          cout << "\n   Levantar dinheiro\n";
          if (s==0) {
            cout << "\nPedimos desculpa, mas nao tem saldo disponivel.\n";
            cin.ignore();
            cin.get();
            break;
          }
          cout << "\nInsira o valor a levantar:";
          cin >> a;
          if (a>s) {
            cout << "\nPedimos desculpa, mas nao tem saldo disponivel para o valor a levantar.\n";
            cout << "\nVai ser pedido novo valor, obrigado.\n";
            cin.ignore();
            cin.get();
          }
          else if(a<=0) {
            cout << "\nIndicou um valor negativo ou igual a 0.\n";
            cout << "\nVai ser pedido novo valor, obrigado.\n";
            cin.ignore();
            cin.get();
            a=s+1; // Este incremento não deixa sair da opcao levantar
          }
        } while(a>s);
        if (s!=0) // Este if é se o saldo for 0 não pode descontar qualquer valor.
          s=s-a;
        break;
      case 3:
        do {
          cout << "\033[2J\033[1;1H";
          cout << "\n   Depositar dinheiro\n";
          cout << "\nInsira o valor a depositar:";
          cin >> a;
          if(a<=0) {
            cout << "\nIndicou um valor negativo ou igual a 0.\n";
            cout << "\nVai ser pedido novo valor, obrigado.\n";
            cin.ignore();
            cin.get();
          }
        }while(a<=0);
        s=s+a;
        break;
      case 4:
        cout << "\nHasta la vista, Baby!\n";
        cin.ignore();
        cin.get();
        break;
      default:
        cout << "\nOpcao Incorrecta.\n";
        cin.ignore();
        cin.get();
        break;
    }
  } while(o != 4);
  return 0;
}
