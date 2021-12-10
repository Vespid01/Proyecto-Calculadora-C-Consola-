
imprimir::imprimir(string _operacion) : operar(_operacion) { }


void imprimir::Obtener_Resultado(void)
{
    float resultado = operar::IA();
    system("cls");

    if(!final)
    {
        cout<<"--------------------------\n  ";
        cout<<separar::operacion<<" = "<<resultado<<endl;
    } else {
        
        cout<<"--------------------------\n  ";
        cout<<separar::operacion<<" "<<resultado<<endl;
    }
}
