#include <iostream>
#include <locale.h>
#include <ctime>
using namespace std;

string formatocitacao (string nomecompleto)
{
	int ultimoespaco = nomecompleto.rfind(" ");
	int primeirosobrenome = nomecompleto.find(" ");

	string ultimoSobrenome = nomecompleto.substr(ultimoespaco + 1); 
	string nome = nomecompleto.substr(0, primeirosobrenome);
	
		string iniciais;
				
		for(int i = 0; i < ultimoespaco; i++)
		{
		if (nomecompleto[i] == ' '){
			iniciais += nomecompleto[i+1];
			iniciais += ". ";
		}
	}
	return ultimoSobrenome + ", " + nome + " " + iniciais;
}

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int dia, int mes, int ano)
    {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    Data()
    {
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
    }

    // Set/Get
    void setDia(int dia)
    {
        this->dia = dia;
    }
    void setMes(int mes)
    {
        this->mes = mes;
    }
    void setAno(int ano)
    {
        this->ano = ano;
    }
    int getDia()
    {
        return this->dia;
    }
    int getMes()
    {
        return this->mes;
    }
    int getAno()
    {
        return this->ano;
    }

    int diasNoMes()
    {
        int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (this->ano % 4 == 0 && (this->ano % 100 != 0 || this->ano % 400 == 0))
        {
            dias[1]++;
        }

        return dias[this->mes - 1];
    }
};

class Contato
{
private:
    string email;
    string nome;
    string telefone;
    Data *dtnasc;

	bool isNumeroValido(string telefone) {
        for (char c : telefone) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true; 
    }
	string formatocitacao (string nomecompleto)
{
	int ultimoespaco = nomecompleto.rfind(" ");
	int primeirosobrenome = nomecompleto.find(" ");

	string ultimoSobrenome = nomecompleto.substr(ultimoespaco + 1); 
	string nome = nomecompleto.substr(0, primeirosobrenome);
	
		string iniciais;
				
		for(int i = 0; i < ultimoespaco; i++)
		{
		if (nomecompleto[i] == ' '){
			iniciais += nomecompleto[i+1];
			iniciais += ". ";
		}
	}
	return ultimoSobrenome + ", " + nome + " " + iniciais;
}
public:
    Contato(string email, string nome, string telefone, Data *dtnasc)
    {
        this->email = email;
        this->nome = nome;
        this->telefone = telefone;
        this->dtnasc = dtnasc;
    }

    Contato()
    {
        this->email = "";
        this->nome = "";
        this->telefone = "";
        this->dtnasc = new Data();
    }

    // Set/Get
    void setEmail(string email)
    {
        if (email.find('@') != string::npos && email.find('.') != string::npos)
            this->email = email;
        else
            cout << "Email inválido" << endl;
    }

    void setNome(string nome)
    {
        if (!nome.empty())
            this->nome = nome;
        else
            cout << "Nome não pode ser vazio" << endl;
    }

    void setTelefone(string telefone)
    {
        if (telefone.length() >= 8 && isNumeroValido(telefone))
            this->telefone = telefone;
        else
            cout << "Telefone invalido" << endl;
    }

    void setDataNascimento(Data *data)
    {
        int anoAtual;
        time_t t = time(0);
        tm *now = localtime(&t);
        anoAtual = now->tm_year + 1900;

        if (data->getAno() >= 1900 && data->getAno() <= anoAtual)
        {
            this->dtnasc = data;
        }
        else
        {
            cout << "Data de nascimento inválida!" << endl;
        }
    }

    string getEmail()
    {
        return this->email;
    }

    string getNome()
    {
        return this->nome;
    }

    string getTelefone()
    {
        return this->telefone;
    }
    int idade()
    {
        time_t t = time(0);
        tm *agr = localtime(&t);
        int anoAtual = agr->tm_year + 1900;
        int idadePessoa = anoAtual - dtnasc->getAno();
        return idadePessoa;
    }
};

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");

    string emailNovo;
    string nomeNovo;
    string telefoneNovo;
    Data *dtnasc;
    int diaNascimento, mesNascimento, anoNascimento;

    int anoAtual;
    time_t t = time(0);
    tm *now = localtime(&t);
    anoAtual = now->tm_year + 1900;

    Contato *contatos = new Contato[10];
    /*
    contatos[0].setNome("Maria Eduarda Alves Moreira");
    contatos[0].setEmail("1numn@gmail.com");
    contatos[0].setTelefone("126458323567568");
    contatos[0].setDataNascimento(new Data(1,1,1993));
    
    contatos[1].setNome("Enzo Rafael Lima Costa");
    contatos[1].setEmail("2numn@gmail.com");
    contatos[1].setTelefone("123566458327568");
    contatos[1].setDataNascimento(new Data(1,1,2001));
    
    contatos[2].setNome("Felipe Andrade Nogueira");
    contatos[2].setEmail("3numn@gmail.com");
    contatos[2].setTelefone("356751264583268");
    contatos[2].setDataNascimento(new Data(1,1,2012));
    
    contatos[3].setNome("Julia Vito Martins de Souza");
    contatos[3].setEmail("4numn@gmail.com");
    contatos[3].setTelefone("127568323566845");
    contatos[3].setDataNascimento(new Data(1,1,1999));
    
    contatos[4].setNome("Isabela Cristina Rocha Lima");
    contatos[4].setEmail("5numn@gmail.com");
    contatos[4].setTelefone("512648323567568");
    contatos[4].setDataNascimento(new Data(1,1,1995));
    
    contatos[5].setNome("Larissa Fernanda dos Santos");
    contatos[5].setEmail("6numn@gmail.com");
    contatos[5].setTelefone("312645823567568");
    contatos[5].setDataNascimento(new Data(1,1,1981));
    
    contatos[6].setNome("Gustavo Souza Ribeiro	");
    contatos[6].setEmail("7numn@gmail.com");
    contatos[6].setTelefone("126475685832356");
    contatos[6].setDataNascimento(new Data(1,1,2003));
    
    contatos[7].setNome("Leonardo Moura Fonseca");
    contatos[7].setEmail("8numn@gmail.com");
    contatos[7].setTelefone("832126453567568");
    contatos[7].setDataNascimento(new Data(1,1,1985));
    
    contatos[8].setNome("Rafael Lima Batista");
    contatos[8].setEmail("9numn@gmail.com");
    contatos[8].setTelefone("124444443567568");
    contatos[8].setDataNascimento(new Data(1,1,2007));
    
    contatos[9].setNome("Ana Beatriz Cardoso Ferreira");
    contatos[9].setEmail("10numn@gmail.com");
    contatos[9].setTelefone("351264583267568");
    contatos[9].setDataNascimento(new Data(1,1,1989));
    
    cout << "teste";
	*/
    for (int i = 0; i < 10; i++)
    {
        Contato aux;
        cout << "Cadastro do contato " << (i + 1) << endl;

        do
        {
            cout << "Digite seu email: ";
            cin >> emailNovo;
            aux.setEmail(emailNovo);
        } while (aux.getEmail() == "");

        do
        {
            cout << "Digite seu nome: ";
            cin.ignore();
			getline(cin, nomeNovo);
            aux.setNome(nomeNovo);
        } while (aux.getNome() == "");

        do
        {
            cout << "Digite seu telefone: ";
            cin >> telefoneNovo;
            aux.setTelefone(telefoneNovo);
        } while (aux.getTelefone() == "");

        do
        {
            cout << "Digite seu dia de nascimento (1-31): ";
            cin >> diaNascimento;
            cout << "Digite seu mês de nascimento (1-12): ";
            cin >> mesNascimento;
            cout << "Digite seu ano de nascimento: ";
            cin >> anoNascimento;

            if (anoNascimento < 1900 || anoNascimento > anoAtual)
            {
                cout << "Ano inválido! Digite um ano entre 1900 e " << anoAtual << "." << endl;
            }
            else if (mesNascimento < 1 || mesNascimento > 12)
            {
                cout << "Mês inválido! Digite um mês entre 1 e 12." << endl;
            }
            else if (diaNascimento < 1 || diaNascimento > 31)
            {
                cout << "Dia inválido! Digite um dia entre 1 e 31." << endl;
            }
            else
            {
                dtnasc = new Data(diaNascimento, mesNascimento, anoNascimento);

                if (diaNascimento > dtnasc->diasNoMes())
                {
                    cout << "Dia inválido para o mês! O mês de " << mesNascimento << " tem " << dtnasc->diasNoMes() << " dias." << endl;
                }
                else
                {
                    aux.setDataNascimento(dtnasc);
                    break;
                }
            }
        } while (true);

        contatos[i] = aux;
    }

	int media = 0;
	int soma = 0;
	int maisVelho = 0;
	int qtdAcimaMedia = 0;
	
	for(int cont1 = 0; cont1 < 10; cont1++)
	{
		soma += contatos[cont1].idade();
		if (contatos[cont1].idade() > maisVelho){
			maisVelho = contatos[cont1].idade();
		}
	}
		media = soma/10;
    
	for(int cont2 = 0; cont2<10; cont2++)
	{
		
		if (contatos[cont2].idade()>media){
			qtdAcimaMedia++;
		}
	}
		
    cout << endl << "====================" << endl;
    
        cout << "Media das idades: " << media << endl;
        for(int contNum = 0; contNum < 10; contNum++)
		{
			if(contatos[contNum].idade() > media){
				cout << "Nome dos contatos acima da media: " << formatocitacao(contatos[contNum].getNome()) << endl;
			}
		}
             cout << "Qtd de contatos acima da media: " << qtdAcimaMedia << endl;
		for(int contNum2 = 0; contNum2 < 10; contNum2++){
			if (contatos[contNum2].idade() == maisVelho){
				cout << "O nome, e-mail e o telefone do contato mais velho: " << formatocitacao(contatos[contNum2].getNome()) 
			 << " | " <<contatos[contNum2].getEmail() << " | " << contatos[contNum2].getTelefone() << endl;
			}
		}
             
        cout << "====================" << endl;
	
	
    delete[] contatos;
    return 0;
}