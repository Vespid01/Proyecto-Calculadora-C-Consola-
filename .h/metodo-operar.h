
// constructor de la clase operar*
operar::operar(string _operacion) : separar(_operacion) {}

// metodo principal, este metodo recorre los arrys de numeros y operadores**
void operar::moveratrasS(int _PosisionInicial)
{
    for (int i = _PosisionInicial; i < IteradorOperadores; i++)
    {
        operadores[i] = operadores[i + 1];
        numerosArray[i + 1] = numerosArray[i + 2];
    }
    IteradorOperadores--;
    iteradorNumerico--;
}

// comvierte de string a char y de char a float
void operar::comvercion(void)
{
    char c[50];
    string n;
    for (int i = 0; i < iteradorNumerico; i++)
    {
        n = numerosStr[i];
        strcpy(c, n.c_str());
        numerosArray[i] = atof(c);
    }
}

// obtiene el valor de donde iniciar a bucar y luego busca si hay 1 par de parentesis o mas para realizar las operasiones dentro de ellos
void operar::parentesis(int _posisionInicial)
{
    for (int i = _posisionInicial; i < IteradorOperadores; i++)
    {
        if (operadores[i] == 'i')

            for (int _i = (i + 1); _i < IteradorOperadores; _i++)
            {
                if (operadores[_i] == 'i') parentesis(_i);
                if (operadores[_i] == 'f')
                {
                    
                    operadores[i] = 'm'; 
                    moveratrasS(_i);
                    multiplicasionD(i+1 , _i);
                    divicion(i+1 , _i);
                    sumaR(i+1, _i);
                    
                }
            }
    }
}

// resuelve todas las multiplicasiones y recorre los numeros te tal forma que elimina la operacion y solo deja el resultado
void operar::multiplicasionD(int _posisionInicial, int _posisionFinal)
{
    for (int i = _posisionInicial; i < iteradorNumerico && i < _posisionFinal; i++)
    {
        if (operadores[i] == 'm')
        {
            numerosArray[i] = numerosArray[i] * numerosArray[i + 1];
            moveratrasS(i);
            i--;
        }
    }
}

// resuelve todas las Diviciones y recorre los numeros te tal forma que elimina la operacion y solo deja el resultado
void operar::divicion(int _posisionInicial, int _posisionFinal)
{
    for (int i = _posisionInicial; i < iteradorNumerico && i < _posisionFinal; i++)
    {
        if (operadores[i] == 'd')
        {
            numerosArray[i] = numerosArray[i] / numerosArray[i + 1];
            moveratrasS(i);
            i--;
        }
    }
}

// resuelve todas las sumas y restas luego recorre los numeros te tal forma que elimina la operacion y solo deja el resultado
void operar::sumaR(int _posisionInicial, int _posisionFinal)
{
    for (int i = _posisionInicial; i < IteradorOperadores && i < _posisionFinal; i++)
    {
        if (operadores[i] == 's')
        {
            numerosArray[i] += numerosArray[i + 1];
            moveratrasS(i);
            i--;
        }
        else if (operadores[i] == 'r')
        {
            numerosArray[i] -= numerosArray[i + 1];
            moveratrasS(i);
            i--;
        }
    }


}

//ordena todos los metodos para hacer que la calculadora funciones por completo, y retorna el valor final 'resultado'
float operar::IA(void)
{
    separar::ordenamiento();
    operar::comvercion();

    operar::parentesis(0);

    operar::multiplicasionD(0, IteradorOperadores);
    operar::divicion(0, IteradorOperadores);
    operar::sumaR(0, iteradorNumerico);

    return numerosArray[0];
}
