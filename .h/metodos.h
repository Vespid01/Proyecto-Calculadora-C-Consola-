
separar::separar(string _operacion)
{
    operacion = _operacion;
    iteradorNumerico = 0;
    IteradorOperadores = 0;
}

void separar::ordenamiento(void)
{
    string concatenar = "", caracter;

    for (int j = 0; j < operacion.size(); j++)
    {
        caracter = operacion[j];
        if      (caracter.compare("+") == 0){numerosStr[iteradorNumerico] = concatenar;concatenar = "", operadores[iteradorNumerico] = 's';iteradorNumerico++;IteradorOperadores++;}
        else if (caracter.compare("-") == 0){numerosStr[iteradorNumerico] = concatenar;concatenar = "", operadores[iteradorNumerico] = 'r';iteradorNumerico++;IteradorOperadores++;}
        else if (caracter.compare("/") == 0){numerosStr[iteradorNumerico] = concatenar;concatenar = ""; operadores[iteradorNumerico] = 'd';iteradorNumerico++;IteradorOperadores++;}
        else if (caracter.compare("*") == 0){numerosStr[iteradorNumerico] = concatenar;concatenar = ""; operadores[iteradorNumerico] = 'm';iteradorNumerico++;IteradorOperadores++;}

        else if (caracter.compare("(") == 0){operadores[iteradorNumerico] = 'i'; if (concatenar.compare("") == 0) numerosStr[iteradorNumerico] = "1"; else numerosStr[iteradorNumerico] = concatenar; concatenar = "";iteradorNumerico++;IteradorOperadores++;}
        else if (caracter.compare(")") == 0){operadores[iteradorNumerico] = 'f'; if (concatenar.compare("") == 0) numerosStr[iteradorNumerico] = "1"; else numerosStr[iteradorNumerico] = concatenar; concatenar = "";iteradorNumerico++;IteradorOperadores++;}

        else concatenar += operacion[j];
    }
    if (concatenar.compare("") != 0){numerosStr[iteradorNumerico] = concatenar;iteradorNumerico++;}
    concatenar = operacion[operacion.size()-1];

    if(concatenar.compare("=")==0) final = true;
}

// Metodos de la clase "operar"
operar::operar(string _operacion) : separar(_operacion) { }

void operar::moveratrasS(int _Posision)
{
    for (int j = _Posision; j < IteradorOperadores; j++)
    {
        operadores[j] = operadores[j+1];
        numerosArray[j+1] = numerosArray[j+2];
    }
    IteradorOperadores--; iteradorNumerico--;
}

void operar::comvercion(void)
{
    char c[50];
    string n;
    for (int j = 0; j < iteradorNumerico; j++)
    {
        n = numerosStr[j];
        strcpy(c, n.c_str());
        numerosArray[j] = atof(c);
    }
}


void operar::parentesis(int _pi)
{
    for (int j = _pi; j < IteradorOperadores; j++)
    {
        if(operadores[j] == 'i')
            for (int _j = (j+1); _j < IteradorOperadores; _j++)
            {
                if(operadores[_j] == 'i') parentesis(_j);
                if(operadores[_j] == 'f')
                {
                    operadores[j] = 'm';
                    moveratrasS(_j);
                    multiplicasionD(j+1,_j);
                    sumaR(j,_j);
                }
            }
    }
}

void operar::multiplicasionD(int _p, int _pf)
{
    for (int j = _p; j < iteradorNumerico && j<_pf; j++)
    {
        if (operadores[j] == 'm'){numerosArray[j] = numerosArray[j] * numerosArray[j+1]; moveratrasS(j); j--;}
    }
}

void operar::divicion(int _p, int _pf)
{
    for (int j = _p; j < iteradorNumerico && j<_pf; j++)
    {
        if (operadores[j] == 'd'){numerosArray[j] = numerosArray[j] / numerosArray[j+1]; moveratrasS(j); j--;}
    }
}


void operar::sumaR(int _p, int _pf)
{
    for (int j = _p; j < IteradorOperadores && j<_pf; j++)
    {
        if      (operadores[j] == 's'){numerosArray[j] += numerosArray[j+1]; moveratrasS(j); j--;}
        else if (operadores[j] == 'r'){numerosArray[j] -= numerosArray[j+1]; moveratrasS(j); j--;}
    }
}

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

imprimir::imprimir(string _operacion) : operar(_operacion) { }

void imprimir::Obtener_Resultado(void)
{
    float resultado = operar::IA();
    system("cls");

    if(!final)
    {
        cout<<"--------------------------\n  ";
        cout<<separar::operacion<<" = "<<resultado;
    } else {
        
        cout<<"--------------------------\n  ";
        cout<<separar::operacion<<" "<<resultado;
    }
}
