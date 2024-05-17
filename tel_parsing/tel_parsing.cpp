/*
Телефонные номера в адресной книге мобильного телефона имеют один из следующих форматов: +7<код><номер> , 8<код><номер> , <номер> , где
<номер> — это семь цифр, а <код> — это три цифры или три цифры в круглых скобках. 
Если код не указан, то считается, что он равен 495. Кроме того, в записи телефонного номера может стоять знак “-” между любыми двумя цифрами (см. пример). 
На данный момент в адресной книге телефона Васи записано всего три телефонных номера и он хочет записать туда ещё один. 
Но он не может понять, не записан ли уже такой номер в телефонной книге. 
Помогите ему! Два телефонных номера совпадают, если у них равны коды и равны номера. Например, +7(916)0123456 и 89160123456 — это один и тот же номер.
*/

#include <iostream>
#include <string>


using namespace std;

void remove_defis(string& s)
{
	for (auto i = s.begin(); i != s.end(); ++i)
		if (*i == '-') 
			i = s.erase(i);
}

string extract_number(string& t)
{
	string result;
	for (auto i = t.end() - 8; i != t.end(); i++)
		result += *i;
	for (size_t i = 0; i < 7; i++)
		t.erase(t.end() - 1);
	return result;
}

string get_code(string& t)
{
	string res;
	size_t append = 0;
	if (*(t.end() - 1) == ')')
		append++;
	for (int i = 3; i > 0; i--)
		res += *(t.end() - i - append);
}

int main()
{
	string t[4], n[4], cd[4];
	const string def_code = "495";
	for(size_t i=0;i<4;i++)
	{
		cin >> t[i];
		remove_defis(t[i]);
		n[i]=extract_number(t[i]);
		if (t[i].empty())
			cd[i] = def_code;
		else
			cd[i] = get_code(t[i]);
	}
	
	return 0;
}

