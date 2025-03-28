// Conexoes do Modulo do LCD
sbit LCD_RS at RB2_bit;
sbit LCD_EN at RB3_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;
sbit LCD_RS_Direction at TRISB2_bit;
sbit LCD_EN_Direction at TRISB3_bit;
sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;

int tamanho_aux;
int opcao_cerveja;
int tamanho_cerveja;
int execucao_cerveja;
int ETAPA_TAMANHO;
int ETAPA_ESCOLHA;
int PASSAR_ESCOLHA;
int PASSAR_TAMANHO;
int EXECUCAO;

// End LCD module connections
void main()
{
TRISB = 0b00000001; //Definindo a entrada B0 como sendo uma ENTRADA, sendo a ENTRADA do botao
TRISA.F0=0; //Definindo como uma sa?da do sistema
TRISA.F1=0; //Definindo como uma sa?da do sistema
TRISA.F2=0; //Definindo como uma sa?da do sistema
TRISA.F3=0; //Definindo como uma sa?da do sistema

PORTA.F0=0;//Definindo com inicialmente desligado
PORTA.F1=0;//Definindo com inicialmente desligado
PORTA.F2=0;//Definindo com inicialmente desligado
PORTA.F3=0;//Definindo com inicialmente desligado

opcao_cerveja=1;
tamanho_cerveja=1;

Lcd_Init(); // Initialize LCD
 Lcd_Cmd(_LCD_CLEAR); // Clear display
 Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off
 Delay_ms(5000);
 Lcd_Out(1,6,"Bem");
 Lcd_Out(2,6,"Vindo!");
 Delay_ms(5000);
 Delay_ms(50);
 Lcd_Out(1,6,"Opcao:");
 Lcd_Out(2,6,"Corona");//Fornece a Cerveja 1 ser escolhida
ETAPA_ESCOLHA=1;
ETAPA_TAMANHO=0;
EXECUCAO=0;
PASSAR_ESCOLHA=0;
PASSAR_TAMANHO=0;

while(1)
 {
         while(ETAPA_ESCOLHA)
         {
          Delay_ms(50);
          if(RB0_bit==1) // Verifica se o botao foi pressionado
          {
            delay_ms(1000); //Aplica um delay
            if(RB0_bit==0) // Verifica novamente se o botao esta pressionado apos o delay
            {
                ETAPA_ESCOLHA=1;
                PASSAR_ESCOLHA=1;
                ETAPA_TAMANHO=0;
                PASSAR_TAMANHO=0;
                EXECUCAO=0;
                opcao_cerveja=opcao_cerveja+1; // Avanca para a proxima opcao
                if(opcao_cerveja == 5) // Reinicia o ciclo
                {
                opcao_cerveja = 1; // Volta para a primeira opcao se atingir o limite
                }
            }
            if(RB0_bit==1)
            {
            Delay_ms(2500);
            if(RB0_bit==1)
            {
               ETAPA_ESCOLHA=0;
               PASSAR_ESCOLHA=0;
               ETAPA_TAMANHO=1;
               PASSAR_TAMANHO=0;
               EXECUCAO=0;
               tamanho_cerveja=1;

                Lcd_Cmd(_LCD_CLEAR); // Clear display
               Lcd_Out(1,6,"Tamanho:");
               Lcd_Out(2,6,"Pequeno");//Fornece opcao de tamanho
               Delay_ms(1000);
            }
            }
            }
            while(PASSAR_ESCOLHA)
            {
            switch(opcao_cerveja)
            {
            case 1:
                Delay_ms(50);
                Lcd_Out(2,6,"Corona");//Fornece a opcao da Cerveja 1
                PASSAR_ESCOLHA=0;
                ETAPA_ESCOLHA=1;
                break;
            case 2:
                Delay_ms(50);
                Lcd_Out(2,6,"Corona Zero");//Fornece a opcao da Cerveja 2
                PASSAR_ESCOLHA=0;
                ETAPA_ESCOLHA=1;
                break;
            case 3:
                Delay_ms(50);
                Lcd_Out(2,6,"Budweiser");//Fornece a opcao da Cerveja 3
                PASSAR_ESCOLHA=0;
                ETAPA_ESCOLHA=1;
                break;
            case 4:
                Delay_ms(50);
                Lcd_Out(2,6,"Hoegaarden");//Fornece a opcao da Cerveja 4
                PASSAR_ESCOLHA=0;
                ETAPA_ESCOLHA=1;
                break;

            default:
                break;
             }
            }
           }

        while(ETAPA_TAMANHO)
        {
        Delay_ms(50);

               if(RB0_bit==1)
               {
               Delay_ms(1000);
               if(RB0_bit==0)
               {
                Delay_ms(100);
                PASSAR_ESCOLHA=0;
                ETAPA_ESCOLHA=0;
                PASSAR_TAMANHO=1;;
                ETAPA_TAMANHO=1;
                EXECUCAO=0;
                tamanho_cerveja++; // Avanca para a proxima opcao de cerveja
                if(tamanho_cerveja == 4) // Reinicia o ciclo do numero da cerveja
                    tamanho_cerveja = 1; // Volta para a primeira opcao se atingir o limite

                }
                if(RB0_bit==1)
                Delay_ms(2500);
                {
                 if(RB0_bit==1)
                {
                 PASSAR_ESCOLHA=0;
                 ETAPA_ESCOLHA=0;
                 PASSAR_TAMANHO=0;;
                 ETAPA_TAMANHO=0;
                 EXECUCAO=1;
                 execucao_cerveja=opcao_cerveja;
                 tamanho_aux=tamanho_cerveja;
                 tamanho_cerveja=1;
                 }
                 }
                 }
        while(PASSAR_TAMANHO)
        {
        switch(tamanho_cerveja)
            {
             case 1:
                Delay_ms(50);
                Lcd_Out(2,6,"Pequeno");//Fornece a opcao Pequena
                Delay_ms(500);
                PASSAR_TAMANHO=0;
                ETAPA_TAMANHO=1;

                break;
             case 2:
                Delay_ms(50);
                Lcd_Out(2,6,"Mediano");//Fornece a opcao Media
                Delay_ms(500);
                PASSAR_TAMANHO=0;
                ETAPA_TAMANHO=1;
                break;
             case 3:
                Delay_ms(50);
                Lcd_Out(2,6,"Gigante");//Fornece a opcao Grande
                Delay_ms(500);
                PASSAR_TAMANHO=0;
                ETAPA_TAMANHO=1;
                break;

              default:
                break;
             }
             }
        }

      while(EXECUCAO)
        {
          Lcd_Cmd(_LCD_CLEAR); // Clear display
          Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off
         Lcd_Out(2,6,"Dispensando...");
        switch(execucao_cerveja)
        {
            case 1:
            {
                Delay_ms(50);
                PORTA.F0=1;
                if(tamanho_aux==1)
                {
                 Delay_ms(3000);
                }
                if(tamanho_aux==2)
                {
                 Delay_ms(5000);
                }
                if(tamanho_aux==3)
                {
                 Delay_ms(7000);
                }
             }

                break;
            case 2:
            {
                Delay_ms(50);
                PORTA.F1=1;
                   if(tamanho_aux==1)
                {
                 Delay_ms(3000);
                }
                if(tamanho_aux==2)
                {
                 Delay_ms(5000);
                }
                if(tamanho_aux==3)
                {
                 Delay_ms(7000);
                }
             }

                break;
            case 3:
            {
                Delay_ms(50);
                PORTA.F2=1;
                   if(tamanho_aux==1)
                {
                 Delay_ms(3000);
                }
                if(tamanho_aux==2)
                {
                 Delay_ms(5000);
                }
                if(tamanho_aux==3)
                {
                 Delay_ms(7000);
                }
             }

                break;
            case 4:
            {
                 Delay_ms(50);
                 PORTA.F3=1;
                    if(tamanho_aux==1)
                {
                 Delay_ms(3000);
                }
                if(tamanho_aux==2)
                {
                 Delay_ms(5000);
                }
                if(tamanho_aux==3)
                {
                 Delay_ms(7000);
                }
             }

                 break;
            default:
                break;
        }
                PORTA=0b00000000;
                 Lcd_Cmd(_LCD_CLEAR); // Clear display
                Delay_ms(1000);
                Lcd_Out(2,6,"Aproveite!!");
                Delay_ms(5000);
                Delay_ms(500);
                opcao_cerveja = 1;
                Lcd_Cmd(_LCD_CLEAR); // Clear display
                Lcd_Out(1,6,"Opcao:");
                Lcd_Out(2,6,"Corona");//Fornece a opcao da Cerveja 1
                PASSAR_ESCOLHA=0;
                ETAPA_ESCOLHA=1;
                PASSAR_TAMANHO=0;
                ETAPA_TAMANHO=0;
                EXECUCAO=0;
        delay_ms(100); // Aguarda um tempo para evitar a verificacao repetida do botao
        }
        }
}