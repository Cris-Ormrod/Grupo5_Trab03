/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              testeCorpoSala.C
*  Letras identificadoras:      CDS
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: cgln - Cristiane - Guilherme - Leonardo - Nath?lia
*
*  $HA Hist?rico de evolu??o:
*     Vers�o  Autor    Data     Observa��es 
*       2.00   cgln  04/11/2017 Elimina��o de c�digo duplicado, reestrutura��o,
*                               inicio da implementa��o dos scripts e testes.
*       1.00   cgln  03/11/2017 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo corpo de sala. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo corpo de sala:
*
*     "=criarCorpoSala"       - chama a fun��o CDS_CriaCorpoSala()
*     "=inserirCorpoSala"     - chama a fun��o CDS_InsereCorpoSala()
*     "=exibirCorpoSala"      - chama a fun��o CDS_ExibeCorpoSala()
*     "=retiraSala"           - chama a fun��o CDS_RetiraCorpoSala()
*     "=limpaCorpoSala"       - chama a fun��o CDS_LimpaCorpoSala()
*     "=liberaCorpoSala"      - chama a fun��o CDS_LiberaCorpoSala()
*     "=qtdMaxSala"           - chama a fun��o CDS_GetQtdMaxCorpoSala()
*     "=tpSala"               - chama a fun��o CDS_GetTipoCorpoSala()
*     "=numeroSala"           - chama a fun��o CDS_GetNumCorpoSala()
*     "=predioSala"           - chama a fun��o CDS_GetPredioCorpoSala()
*     "=andarSala"            - chama a fun��o CDS_GetAndarCorpoSala()
*     "=exibirDispSal"        - chama a fun��o CDS_ExibeDisponibilidadeCorpoSala()
*     "=reservarSala"         - chama a fun��o CDS_ReservaSala()
***************************************************************************/
 
#include    <string.h>
#include    <stdio.h>
 
#include    "TST_ESPC.H"
 
#include    "generico.h"
#include    "lerparm.h"

#include    "sala.h"
#include    "CorpoSala.h"
#include    "lista.h"
 
/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_CDS_CMD          "=criarCorpoSala"
#define     INSERIR_CDS_CMD        "=inserirCorpoSala"
#define     EXIBIR_CDS_CMD         "=exibirCorpoSala"
#define     RETIRA_SALA_CDS_CMD    "=retiraSala"
#define     LIMPA_CDS_CMD          "=limpaCorpoSala" 
#define     LIBERA_CDS_CMD         "=liberaCorpoSala" 
#define     GET_QTD_MAX_CDS_CMD    "=qtdMaxSala"  
#define     GET_TIP_CDS_CMD        "=tpSala"  
#define     GET_NUM_CDS_CMD        "=numeroSala" 
#define     GET_PREDIO_CDS_CMD     "=predioSala"
#define     GET_AND_CDS_CMD        "=andarSala"
#define     EXIBIR_DISP_CDS_CMD    "=exibirDispSala"
#define     RESERVAR_CDS_CMD       "=reservarSala"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/
 
 
/***********************************************************************
*
*  $FC Fun��o: CDS Efetuar opera��es de teste espec�ficas para o m�dulo corpo de sala
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     Corpo de Sala sendo testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/


   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
 
      CDS_tpCondRet CondRetObtido ;
      CDS_tpCondRet CondRetEsperada ;
      
	  TST_tpCondRet Ret ;

	  int NumLidos = -1 ;

	  char codSala[6] ;
	  int maxAlunos = 0 ;
	  int ValorObtidoMaxAlunos ;
	  int tpSala ;
	  int ValorObtidoTpSala ;
	  int numSala ;
	  int ValorObtidoNumSala ;
	  char predio[10] ;
	  char ValorObtidoPredio[10] ;
	  int andar ;
	  int ValorObtidoAndar ;
	  int dia, horIni, horFim, qtd, lab ;


      /* Testar CDS Criar Corpo de Sala  */
 
         if ( strcmp( ComandoTeste , CRIAR_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "i" ,
                                &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */
 
            CondRetObtido = CDS_CriaCorpoSala ( ) ;
  
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar corpo de sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Criar Corpo de Sala */
		

	  /* Testar CDS Insere Sala */
 
         else if ( strcmp( ComandoTeste , INSERIR_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "siii" ,
                                codSala, &maxAlunos, &tpSala, &CondRetEsperada ) ;
            if ( NumLidos != 4 )
            {
               return TST_CondRetParm ;
            } /* if */
   
            CondRetObtido = CDS_InsereCorpoSala ( codSala, maxAlunos, tpSala ) ; 
 
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao inserir sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Insere Sala */


      /* Testar CDS Retira Sala */
 
         else if ( strcmp( ComandoTeste , RETIRA_SALA_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "si" ,
                                codSala, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */
   
            CondRetObtido = CDS_RetiraCorpoSala ( codSala ) ; 
 
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao inserir sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Retira Sala */


	  /* Testar CDS Exibe Corpo Sala */

		 else if ( strcmp( ComandoTeste , EXIBIR_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "i" ,
                                &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */
   
            CondRetObtido = CDS_ExibeCorpoSala ( ) ; 
 
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao exibir sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Exibe Corpo Sala */


	  /* Testar CDS Limpa Corpo Sala */

		 else if ( strcmp( ComandoTeste , LIMPA_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "i" ,
                                &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */
   
            CondRetObtido = CDS_LimpaCorpoSala ( ) ; 
 
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao exibir sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Limpa Corpo Sala */
		 

	  /* Testar CDS Libera Corpo Sala */

		 else if ( strcmp( ComandoTeste , LIBERA_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "i" ,
                                &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */
   
            CondRetObtido = CDS_LiberaCorpoSala ( ) ; 
 
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao liberar corpo de sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Libera Corpo Sala */


      /* Testar CDS Get Quantidade Maxima de Alunos de Sala */
 
         else if ( strcmp( ComandoTeste , GET_QTD_MAX_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "isi" ,
                                &maxAlunos, codSala, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */
   
            CondRetObtido = CDS_GetQtdMaxCorpoSala ( &ValorObtidoMaxAlunos, codSala) ; 
			
			Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter quantidade maxima de alunos na sala.\n" );

			if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararInt( maxAlunos , ValorObtidoMaxAlunos ,
                                    "Conteudo errado no numero maximo de alunos na sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Get Quantidade Maxima de Alunos de Sala */


      /* Testar CDS Get Tipo de Sala */
 
         else if ( strcmp( ComandoTeste , GET_TIP_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "isi" ,
                                &tpSala, codSala, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */
   
            CondRetObtido = CDS_GetTipoCorpoSala ( &ValorObtidoTpSala, codSala) ; 
			
			Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter tipo de sala.\n" );

			if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararInt( tpSala , ValorObtidoTpSala ,
                                    "Conteudo errado no tipo de sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Get Tipo de Sala */


      /* Testar CDS Get Numero da Sala */
 
         else if ( strcmp( ComandoTeste , GET_NUM_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "isi" ,
                                &numSala, codSala, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */
   
            CondRetObtido = CDS_GetNumCorpoSala ( &ValorObtidoNumSala, codSala) ; 
			
			Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter n�mero da sala.\n" );

			if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararInt( numSala , ValorObtidoNumSala ,
                                    "Conteudo errado no numero de sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Get Numero da Sala */


      /* Testar CDS Get Predio da Sala */
 
         else if ( strcmp( ComandoTeste , GET_PREDIO_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "ssi" ,
                                predio, codSala, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */
   
            CondRetObtido = CDS_GetPredioCorpoSala ( ValorObtidoPredio, codSala) ; 
			
			Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter predio da sala.\n" );

			if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararString( predio , ValorObtidoPredio ,
                                    "Conteudo errado do predio de sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Get Predio da Sala */


	  /* Testar CDS Get Andar da Sala */
 
         else if ( strcmp( ComandoTeste , GET_AND_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "isi" ,
                                &andar, codSala, &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */
   
            CondRetObtido = CDS_GetAndarCorpoSala ( &ValorObtidoAndar, codSala) ; 
			
			Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter andar da sala.\n" );

			if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

			return TST_CompararInt( andar , ValorObtidoAndar ,
                                    "Conteudo errado no andar da sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Get Andar da Sala */
	  
		 
   	  /* Testar CDS Exibir Disponibilidade de Sala */

		 else if ( strcmp( ComandoTeste , EXIBIR_DISP_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "si" ,
                                codSala, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */
   
            CondRetObtido = CDS_ExibeDisponibilidadeCorpoSala ( codSala ) ; 
 
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao exibir disponibilidade de sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Exibir Disponibilidade de Sala  */

 
	  /* Testar CDS Reservar Sala */
 
         else if ( strcmp( ComandoTeste , RESERVAR_CDS_CMD ) == 0 )
         {
 
            NumLidos = LER_LerParametros( "iiiiii" ,
                                &dia, &horIni, &horFim, &qtd, &lab, &CondRetEsperada ) ;
            if ( NumLidos != 6 )
            {
               return TST_CondRetParm ;
            } /* if */
   
            CondRetObtido = CDS_ReservaSala ( dia, horIni, horFim, qtd, lab ) ; 
 
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao inserir sala.\n" ) ;
 
         } /* fim ativa: Testar CDS Reservar Sala */

   } /* Fim fun��o: CDS Efetuar opera��es de teste espec�ficas para o m�dulo corpo de sala */
   
/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/