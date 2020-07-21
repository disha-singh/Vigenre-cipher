 #include<iostream.h> 
 #include<conio.h> 
 #include<stdio.h> 
 #include<stdlib.h> 
 #include<string.h> 
 #include<ctype.h>  
 class vigenere 
 {  
     public:       
     char *key (char string[1000],char key1[50]) 
     {     
         char key2[600];     
         strcpy (key2, key1);     
         int i,x,y,ss,sk;    
         ss = strlen (string);   
         sk = strlen (key1);   
         x = ss / sk;   
         y = ss % sk;   
         for (i=1;i<x;i++) 
         {      
             strcat(key2,key1);
         }
         x = strlen (key2); 
         for (i = 0; i < y; i++)
         {
             key2[x] = key1[i];
             x++;
         }
          return key2; }
          char *encrypt (char string[1000], char key2[600])    
          {       
              char em[1000];       
              for(int i=0;i<strlen(string);i++)       
              {           
                  if (string[i] >= 65 && string[i] <= 90)             
                  {                 
                      em[i] = (string[i] + key2[i]) % 26;                 
                      em[i] += 'A';                 
                      cout<<em[i];
                   }         
                   else
                      em[i] = string[i];
            }  
            return em;
          }
          char *decrypt (char string[1000], char key2[600])   
          {       
              char dm[1000];       
              for(int i=0;i<strlen(string);i++)       
              {           
                  if (string[i] >= 65 && string[i] <= 90)           
                  {               
                      dm[i] = (string[i] - key2[i] + 26) % 26;dm[i] += 'A';                    
                      cout<<dm[i];
                  }
                  else
                  dm[i] = string[i];
        }
        return dm;
          }
 };  
int main ( )  
{      
    vigenere v;      
    char string[1000],key1[50],key2[1000],em[10000],dm[1000];      
    int ch;      
    char ans;      
    clrscr( );      
    while(1)      
    {      
        cout << "\n\nMenu\n";      
        cout<<"1.Encrypt\n";      
        cout<< "2.Decrypt\n";      
        cout<<"3.Exit\n\n";      
        cout<<"Enter your choice\n";      
        cin>>ch;
        switch(ch)        
        {            
            case 1: cout<< "Enter the text to be encrypted in capital letters\n";              
             gets(string);              
             cout<<"Enter the key\n";              
             gets(key1);              
             cout<<"The encrypted text is\n";              
             ofstream file;              
             file.open("Encrypt.txt" , ios::out | ios::app);
             file<<v.encrypt(string,v.key(string,key1))<<”\n”;              
             file.close();                
            case 2: cout << "Enter text to be decrypted in capital letters\n";             
             gets (string);             
             cout<<"Enter the key\n";             
             gets(key1);             
             cout<<"The decrypted text is\n";             
             ofstream f;             
             f.open("Decrypt.txt" , ios::out | ios::app);             
             f<<v.decrypt(string,v.key(string,key1))<<”\n”;             
             f.close();           
            case 3:exit(0);  
            default:cout<<"Invalid choice\n";
        }
    }
}
          
