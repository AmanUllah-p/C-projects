
class login
{
	string username,password,u,p;
	public:
		login()
		{
			username="admin";password="123";
		}
		void get();
};
void login:: get()
{
a:  system("cls");
	cout<<"\n\n\n\n\n\t\t\t USERNAME   -> ";
	getline(cin,u);
	while(u!=username)
	{
		cout<<"\n\t\t\t WRONG USERNAME ";
		getch();
		goto a;
	}
	cout<<"\n\t\t\t PASSWORD   -> ";
	getline(cin,p);

	
	while(p!=password)
	{
		goto a;
	}
	
	if(u==username&&p==password)
	{
		cout<<"\n\t\t\t LOGIN APPROVED... \n";
	}
	sleep(1);
	system("cls");
}


