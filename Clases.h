#include <vector>
using std::cout;
using std::endl;
class Objeto
{
    private:
        float Precio;
        int ID;
        std::string Nombre;
        int cantidad;
    public:
        Objeto()
        {
            this->Precio = 0;
            this->ID = 00000;
            this->Nombre = " ";  
            this->cantidad = 0;
        };
        Objeto(std::string nombre, float precio, int id, int cantidad)
        {
            this->Nombre = nombre;
            this->Precio = precio;
            this->ID = id;
            this->cantidad = cantidad;
        };
        void SetID(int id)
        {
            this->ID = id;
        };
        int GetID()
        {
            return this->ID;
        };
        void SetPrecio(float precio)
        {
            this->Precio = precio;
        };
        int GetPrecio()
        {
            return this->Precio;
        };
        void SetNombre(std::string nombre)
        {
            this->Nombre = nombre;
        };
        std::string GetNombre()
        {
            return this->Nombre;
        };
        void setCantidad(int cantidad)
        {
            this->cantidad = cantidad;
        };
        int getCantidad()
        {
            return this->cantidad;
        };
};
class Tienda
{
    public:
        Tienda()
        {
            this->Nombre = " ";
        };
        std::string GetNombre()
        {
            return this->Nombre;
        };
        void setName(std::string name)
        {
            this->Nombre = name;
        }
        void anadirProducto(Objeto objeto)
        {
            Productos.push_back(objeto);
        };
        void imprimirProductos()
        {
            //Se ciclan los productos dentro de la tienda y se imprime el nombre
            Objeto aux;
            for(int i=0; i<Productos.size();i++)
            {
                aux = Productos.at(i);
                std::cout<<i+1<<".-"<<aux.GetNombre()<<
                " $"<<aux.GetPrecio()<<" disponibles: "<<aux.getCantidad()<<
                std::endl;
            }
        };
        Objeto getProducto(int posicion)
        {
            //Retorna el producto seleccionado y reduce la cantidad de estos
            Objeto aux;
            aux = Productos.at(posicion);
            if(aux.getCantidad()==0)
            {
                Objeto vacio;
                cout<<"Ya no hay mas de ese producto"<<endl;
                return vacio;
            }
            else
            {
                Productos.at(posicion).setCantidad(aux.getCantidad()-1);
                return aux;
            }
        }
        int cantidadProductos()
        {
            return this->Productos.size();
        }
    private:
        std::string Nombre;
        std::vector<Objeto> Productos;
};
class Usuario
{
    public:
        Usuario()
        {
            Nombre=" ";
            contrasena=" ";
            ID=" ";
        };
        Usuario(std::string name, std::string contrasena, std::string id)
        {
            this->Nombre=name;
            this->contrasena=contrasena;
            this->ID=id;            
        };
        void SetNombre(std::string nombre)
        {
            this->Nombre = nombre;
        };
        std::string GetNombre()
        {
            return this->Nombre;
        };
        void SetContrasena(std::string contrasena)
        {
            this->contrasena = contrasena;
        };
        std::string GetContrasena()
        {
            return this->contrasena;
        };
        void SetID(std::string id)
        {
            this->ID = id;
        };
        std::string GetID()
        {
            return this->ID;
        };
    protected:
        std::string Nombre;
        std::string contrasena;
        std::string ID;
};
class Carrito
{
    private:
        std::vector<Objeto> Objetos;
    public:
        Carrito()
        {
            std::vector <Objeto> Objetos;
        }
        void ImprimirCarrito()
        {
            //Se cicla dentro del vector que posee los productos, y se muestran en la consola
            std::string nombre;
            for(int i=0; i<Objetos.size();i++)
            {
                if(Objetos.at(i).GetNombre() == " ") continue;
                if(i==Objetos.size()-1) cout<<Objetos.at(i).GetNombre()<<endl;
                else cout<<Objetos.at(i).GetNombre()<<", ";
            }
        };
        void SetCarrito(Objeto obc)
        {
            Objetos.push_back(obc);
        };
        Objeto GetObjeto(int x)
        {
            return Objetos.at(x);
        };
        void BorrarCarrito()
        {
            Objetos.clear();
        };
        int getLongitud()
        {
            return Objetos.size();
        };
};
class Comprador : public Usuario
{
    public:
        Comprador()
        {
            Nombre=" ";
            contrasena=" ";
            ID=" ";
            Balance=0;
        };
        Comprador(std::string name, std::string contrasena, std::string id, double balance)
        {
            this->Nombre=name;
            this->contrasena=contrasena;
            this->ID=id;
            this->Balance=balance;      
        };
        void SetBalance(double balance)
        {
            this->Balance += balance;
        };
        double GetBalance()
        {
            return this->Balance;
        };
        
        void AgregarCarrito(Objeto ob)
        {
            //Llama a la funcion del carrito para anadir objetos
            carrito.SetCarrito(ob);
        };
        void VerCarrito()
        {
            //Llama a la funcion del carrito para que se imprima
            if(carrito.getLongitud()==0) std::cout<<"El carro esta vacio"<<std::endl;
            else carrito.ImprimirCarrito();
        };
        void ComprarCarrito()
        {
            //Se cicla dentro del vector del carrito para ver la suma del total de los productos
            //Si el balance es suficiente para comprar el carrito, se efectua la compra, 
            //caso contrario, no ocurre esto
            double sum=0;
            for (int i = 0; i < carrito.getLongitud(); i++)
            {
                sum+=carrito.GetObjeto(i).GetPrecio();
            }
            if(sum>this->Balance)
            {
                std::cout<<"No cuenta con los fondos necesarios"<<std::endl;
                std::cout<<"Fondos necesarios: "<< sum <<std::endl;
                std::cout<<"Fondos actuales: "<< Balance<<std::endl;
            }
            else
            {
                std::cout<<"Total a pagar: "<<sum<<std::endl;
                Balance-=sum;
                this->EliminarCarrito();
                std::cout<<"*Compra exitosa*"<<std::endl;
                std::cout<<"Dinero restante en la cuenta: "<<Balance<<std::endl;
            }         
        };
        void EliminarCarrito()
        {
            //Se borran los valores del carritoS
            carrito.BorrarCarrito();
        };
    private:
        double Balance;
        Carrito carrito;
};