#include <iostream>
#include <string.h>
#include "Clases.h"
using std::cout;
using std::endl;
using std::cin;
int main()
{
    //Se crean variables necesarias para la seleccion del menu
    int op=0,op1=0,op2=0; 
    std::string ID, password;
    //Se crea un usuario, y las tiendas que van a vender productos
    Comprador usuario1("José Sánchez","1234","jcsg",500.0);
    Tienda tienda, tienda2;
    tienda.setName("Panaderia El buen pan");
    tienda2.setName("Playeras de Juan");
    //Se anaden los productos que van a vender las tiendas a la aplicacion
    tienda.anadirProducto(Objeto("Pastel de MilkyWay",200.0,1,5));
    tienda.anadirProducto(Objeto("Magdalena",9.0,2,10));
    tienda.anadirProducto(Objeto("Pan tradicional",20.99,3,15));
    tienda2.anadirProducto(Objeto("Playera polo roja",600,1,5));
    tienda2.anadirProducto(Objeto("Playera basica azul",300,2,10));
    tienda2.anadirProducto(Objeto("Camisa manga larga blanca",1000,3,3));
    while(true)
    {
        //Inicio de sesion
        cout<<"Ingrese su ID: ";
        cin>>ID;
        cout<<"Ingrese su contrasena: ";
        cin>>password;
        if(usuario1.GetID()==ID && usuario1.GetContrasena()==password)
        {
            while(true)
            {
                //Opciones
                cout<<"Que desea hacer?"<<endl;
                cout<<"1.-Ver tiendas"<<endl;
                cout<<"2.-Ver Carrito"<<endl;
                cout<<"3.-Eliminar Carrito"<<endl;
                cout<<"4.-Comprar Carrito"<<endl;
                cout<<"5.-Ingresar dinero"<<endl;
                cout<<"6.-Salir"<<endl;
                cin>>op;
                if (op==1)
                {
                    //Se despliegan las tiendas disponibles
                    cout<<"1.- "<<tienda.GetNombre()<<endl;
                    cout<<"2.- "<<tienda2.GetNombre()<<endl;
                    cout<<"Ingrese el numero de la tienda, (-1 para salir)"<<endl;
                    cin>>op1;
                    //Dependiendo de la tienda escogida se despliegan los productos disponibles, y se agregan
                    //los deseados al carrito
                    if(op1==1)
                    {
                        cout<<"Los articulos disponibles son: "<<endl;
                        while (true)
                        {
                            tienda.imprimirProductos();
                            cout<<"Que quiere agregar a su carrito? (ingresa el numero, -1 para terminar)"<<endl;
                            cin>>op2;
                            if(op2==-1) break;  
                            else if(op2>tienda.cantidadProductos() || op2<-1) throw "Ingrese una opcion correcta";                      
                            usuario1.AgregarCarrito(tienda.getProducto(op2-1));
                        }                        
                    }
                    else if(op1==2)
                    {
                        cout<<"Los articulos disponibles son: "<<endl;
                        while (true)
                        {
                            tienda2.imprimirProductos();
                            cout<<"Que quiere agregar a su carrito? (ingresa el numero, -1 para terminar)"<<endl;
                            cin>>op2;
                            if(op2==-1) break;                        
                            else if(op2>tienda.cantidadProductos() || op2<-1) throw "Ingrese una opcion correcta";                      
                            usuario1.AgregarCarrito(tienda2.getProducto(op2-1));
                        }      
                    }
                    else if(op1==-1) break;
                }
                else if (op==2)
                {
                    //Se despliegan los productos dentro del carrito
                    usuario1.VerCarrito();
                }
                else if (op==3)
                {
                    //Se eliminan los productos del carrito
                    usuario1.EliminarCarrito();
                    cout<<endl;
                }
                else if (op==4)
                {
                    //Se pagan los productos dentro del carrito
                    usuario1.ComprarCarrito();
                    cout<<endl;
                    cout<<"Su pedido llegara en aproximadamente 30 minutos"<<endl;
                }
                else if (op==5)
                {
                    //Se ingresa dinero a la cuenta
                    double balanceN=0;
                    cout<<"Balance actual: "<<usuario1.GetBalance()<<endl;
                    cout<<"Cuanto dinero gusta ingresar? ";
                    cin>>balanceN;
                    usuario1.SetBalance(balanceN);
                    cout<<"Balance actual: "<<usuario1.GetBalance()<<endl;
                    cout<<endl;
                }
                else if (op==6)
                {
                    //Sale del menu y termina el codigo
                    cout<<"Gracias por usar nuestro servicio"<<endl;
                    break;
                }
                else
                {
                    //Opcion para una eleccion incorrecta
                    cout<<"Ingrese una opcion correcta"<<endl;
                    cout<<endl;
                }
            }
            break;
        }
    }
    return 0; 
};