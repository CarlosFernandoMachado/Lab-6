# include <iostream>
# include "game.h"
# include "user.h"
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void imprimiruser(vector<User>&arreglo);
void imprimirgames(vector<Game>&arreglo);
bool validar(vector<Game>&arreglo, int id);
bool validaruser(vector<User>&arreglo,string,string,int&);
bool validarfriend(vector<User>&arreglo, string,string);

int main(int argc, char*argv[]){
	int menu = 1;
	bool valida;
	vector<User> usuarios;
	vector<Game> games;
	while(menu){
		cout << "0-salir\n1-Agregar usuario\n2-Modificar Usuario\n3-Eliminar usuario\n4-Agregar juego\n5-Eliminar juegos\n6-Listar usuario\n7-Listar juegos" << endl;
		cin >> menu;
		if(menu == 1){
			string nombre, password;
			cout << "Ingrese su username: ";
			cin >> nombre;
			cout << "Ingrese su password: ";
			cin >> password;
			usuarios.push_back(User(nombre,password));
		}else if(menu == 2){
			imprimiruser(usuarios);
			int opcion;
			string username,password;
			cout << "Escriba el nombre del usuario: " << endl;
			cin >> username;
			cout << "Escriba la contraseña: " << endl;
			cin >> password;
			valida = validaruser(usuarios,username,password,opcion);
			if(valida){
				valida = usuarios[opcion].isValidPassword(username,password);
				if (valida){
					cout << "1-Agregar juego\n2-Eliminar juego\n3-Cambiar contraseña\n4-Agregar amigo" << endl;
					cin >> menu;
					if(menu == 1){//agregar juego
						int id;
						cout << "Ingrese el numero de juego que desea agregar" << endl;
						cin >> id;
						valida = validar(games,id);
						if(valida){
							valida = usuarios[opcion].addGame(id);
							if(!valida){
								cout << "Ha ocurrido un error..." << endl;	
							}else{
								cout << "BIEN HECHO" << endl;
							}
						}else{
							cout << "NO EXISTE" << endl;
						}
					}else if(menu == 2){//eliminar juego
						int id;
						usuarios[opcion].juegos();
						cout << "Ingrese la posicion del juego que desea eliminar: ";	
						cin >> id;
						usuarios[opcion].deleteGame(id);
					}else if(menu == 3){//nueva contraseña
						string password;
						cout << "Ingrese su nueva contraseña: ";
						cin >> password;
						usuarios[opcion].changePassword(password);
					}else if(menu == 4){//agregar amigo
						string nombre;
						cout << "Ingrese el nombre de su \"amigo\":" << endl;
						cin >> nombre;
						valida = validarfriend(usuarios,nombre,username);
						if(valida){
							usuarios[opcion].addFriend(nombre);
							cout << "BIEN HECHO" << endl;
						}else{
							cout << "NO EXISTE" << endl;
						}
					} 
				}else{
					cout << "No puede modificar este usuario" << endl;
				}
			}else{
				cout << "ERROR" << endl;
			}
		}else if(menu == 3){
			imprimiruser(usuarios);
			int opcion;
			cout << "Que usuario desea eliminar (posicion): " << endl;
			cin >> opcion;
			if(opcion < usuarios.size() && opcion >= 0){
				usuarios.erase(usuarios.begin()+opcion);
			}else{
				cout << "uhmmm....esa posicion no existe" << endl;
			}
		}else if(menu == 4){
			int id;
			string name;
			int year;
			string developers;
			string genre;
			cout << "Ingrese el id del juego: ";
			cin >> id;
			cout << "Ingrese el nombre del juego: ";
			cin >> name;
			cout << "Ingrese el año del juego: ";
			cin >> year;
			cout << "Ingrese el developer del juego: ";
			cin >> developers;
			cout << "Ingrese el genre del juego: ";
			cin >> genre;
			games.push_back(Game(id,name,year,developers,genre));
			cout << "BIEN HECHO" << endl;
		}else if(menu == 5){
			imprimirgames(games);
			int opcion;
			cout << "Que juego desea eliminar (posicion): " << endl;
			cin >> opcion;
			if(opcion < games.size() && opcion >= 0){
				games.erase(games.begin()+opcion);
			}else{
				cout << "uhmmm....esa posicion no existe" << endl;
			}
		}else if(menu == 6){
			imprimiruser(usuarios);
		}else if(menu == 7){
			imprimirgames(games);
		}
		cout << "" << endl;
	}
	return 0;
}
void imprimiruser(vector<User>&arreglo){
	for(int i = 0; i < arreglo.size();i++)
		arreglo[i].toString();
}
void imprimirgames(vector<Game>&arreglo){
	for(int i = 0; i < arreglo.size();i++){
		arreglo[i].toString();
	}
}
bool validar(vector<Game>&arreglo, int id){
	for(int i = 0; i < arreglo.size();i++){
		if(arreglo[i].getId() == id){
			return true;
		}
	}
	return false;
}
bool validaruser(vector<User>&arreglo,string nombre,string pass,int& j){
	for(int i = 0; i < arreglo.size();i++){
		if(arreglo[i].isValidPassword(nombre,pass)){
			j = i;
			return true;
		}
	}
	return false;
}
bool validarfriend(vector<User>&arreglo, string nombre, string user){
	for(int i = 0; i < arreglo.size();i++){
		if(arreglo[i].getUsername() == nombre && nombre != user){
			return true;
		}
	}
	return false;
}
