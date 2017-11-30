/***************************************************************************
*  $MCI Modulo de implementacao: CDS  Corpo de Salas
*
*  Arquivo gerado:             CorpoSala.c
*  Letras identificadoras:     CDS
*
*  Nome da base de software:    Arcabouco para a automacao de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza??o dos testes de modulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: cgln - Cristiane - Guilherme - Leonardo - Nathalia
*
*  $HA Hist?rico de evolu??o:
*     Vers?o  Autor    Data     Observacoes
*     3       cgln  04/nov/2017 manutencao das funcoes do modulo
*     2       cgln  02/nov/2017 unificacao de todos os modulos em um so projeto
*     1       cgln  31/out/2017 inicio desenvolvimento
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sala.h"
#include "lista.h"
#include "CorpoSala.h"

/***********************************************************************
*
*  $TC Tipo de dados: CDS Corpo Sala
*
***********************************************************************/

	typedef struct corposala{

		List * Sala ;
		/* Cabeca da lista de salas */

	} CorpoSala ;


/*****  Dados encapsulados no modulo  *****/

	static CorpoSala * CorpoS ;
	/* instância de corpo de sala armazenada por este módulo */


/*****  Protótipos das funções encapsuladas no módulo  *****/

	SAL_tpSala* CDS_BuscaCodCorpoSala( char *codigo ) ;
	SAL_tpSala* CDS_BuscaDispo( int dia, int horini, int horfim,int qtd, int lab ) ;

 
/***************************************************************************
* Funcao: CDS  &Cria Corpo Sala
*  ****/

	CDS_tpCondRet CDS_CriaCorpoSala ()
	{

		CorpoS = ( CorpoSala * ) malloc( sizeof( CorpoSala )) ;
		//createList(&CorpoS->Sala);
    
		if ( createList( &(CorpoS->Sala )) != LIS_CondRetOK )
		{
			return CDS_CondRetFaltouMemoria ;
		} /* if */

		return CDS_CondRetOK ;

	} /* Fim funcao: CDS  &Cria Corpo Sala */
 
/***************************************************************************
* Funcao: CDS  &Busca Codigo Corpo Sala
*  ****/

	SAL_tpSala* CDS_BuscaCodCorpoSala ( char * codigo )
	{ 

		char cod[5] ;
		unsigned int i=0, size ; 
    
		SAL_tpSala * s = NULL ;
    
		list_size( CorpoS->Sala, &size ) ;
    
		first( CorpoS->Sala ) ;
    
		for ( i = 0;i < size; i++ ) 
		{
			get_val_cursor( CorpoS->Sala, ( void** ) &s ) ;
			SAL_getCodigo( s, cod ) ;
			if ( strcmp( codigo,cod ) == 0 )
			{
				return s ;
			} /* if */

			next( CorpoS->Sala ) ;
	    } /* for */

		return NULL ;

	} /* Fim funcao: CDS &Busca Codigo Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Insere Corpo Sala
*  ****/

	CDS_tpCondRet CDS_InsereCorpoSala( char * codigo, int maxAlunos, int eLaboratorio )
	{

		SAL_tpSala * s ;
    
		if ( CDS_BuscaCodCorpoSala( codigo ) != NULL )
		{
			return CDS_CondRetSalaJaCadastrada ;
		} /* if */
    
		SAL_criarSala( &s, codigo, maxAlunos, eLaboratorio ) ;
    
		if ( s == NULL )
		{
			return CDS_CondRetFaltouMemoria ;
		} else
		{
			push_back( CorpoS->Sala, s) ;
			return CDS_CondRetOK ;
		} /* if */

	}/* Fim funcao: CDS &Insere Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Retira Corpo Sala
*  ****/

	CDS_tpCondRet CDS_RetiraCorpoSala( char * codigo )
	{

		SAL_tpSala * s ;
    
		s = CDS_BuscaCodCorpoSala( codigo ) ;
    
		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;
		} else
		{
			pop_cursor( CorpoS->Sala, ( void** ) &s ) ;
			return CDS_CondRetOK ;
		} /* if */

	} /* Fim funcao: CDS &Retira Corpo Sala */
	
/***************************************************************************
* Funcao: CDS  &Exibe Corpo Sala
*  ****/

	CDS_tpCondRet CDS_ExibeCorpoSala ()
	{

		unsigned int i, tam = 0 ;
		SAL_tpSala  * s ;
	
		list_size( CorpoS->Sala, &tam ) ;

		if ( tam == 0 )
		{
			printf( "\n\nNao ha salas cadastradas.\n" ) ;
			return CDS_CondRetCDSVazio ;
		} /* if */

		first( CorpoS->Sala ) ;

		for ( i = 0; i < tam; i++ )
		{
			get_val_cursor( CorpoS->Sala, ( void** ) &s ) ;
			SAL_printSala( s ) ;
			next( CorpoS->Sala ) ;
			printf("\n") ;
		}

		return CDS_CondRetOK ;

	} /* Fim funcao: CDS &Exibe Corpo Sala */
	
/***************************************************************************
* Funcao: CDS  &Libera Corpo Sala
*  ****/

	CDS_tpCondRet CDS_LiberaCorpoSala ()
	{

		clear1( CorpoS->Sala ) ;
		free( CorpoS ) ;
		return CDS_CondRetOK ; 

	} /* Fim funcao: CDS &Libera Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Limpa Corpo Sala
*  ****/

	CDS_tpCondRet CDS_LimpaCorpoSala ()
	{

		unsigned int size=0 ;
		list_size( CorpoS->Sala, &size ) ;
		if (size == 0)
		{
			return CDS_CondRetCDSVazio ;
		} /* if */
    
		clear1( CorpoS->Sala ) ;
		return CDS_CondRetOK ;

	} /* Fim funcao: CDS &Limpa Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Get Qtd Max Corpo Sala
*  ****/

	CDS_tpCondRet CDS_GetQtdMaxCorpoSala( int * max, char * cod )
	{
		SAL_tpSala * s ;
		s = CDS_BuscaCodCorpoSala( cod ) ;
	
		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;
		} else
		{
			SAL_getMaxAlunos( s, max ) ;
			return CDS_CondRetOK ;
		} /* if */

	} /* Fim funcao: CDS &Get Qtd Max Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Get Tipo Corpo Sala
*  ****/

	CDS_tpCondRet CDS_GetTipoCorpoSala( int * tipo, char * cod )
	{
		SAL_tpSala * s ;
		s = CDS_BuscaCodCorpoSala( cod ) ;

		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;
		} else
		{
			SAL_getELaboratorio( s, tipo ) ;
			return CDS_CondRetOK ;
		} /* if */

	} /* Fim funcao: CDS &Get Tipo Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Get Num Corpo Sala
*  ****/

	CDS_tpCondRet CDS_GetNumCorpoSala( int * num, char * cod )
	{
		SAL_tpSala * s ;
		s = CDS_BuscaCodCorpoSala( cod ) ;

		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;
		} else
		{
			SAL_getNumero ( s, num ) ;
			return CDS_CondRetOK ;
		} /* if */

	} /* Fim funcao: CDS &Get Num Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Get Predio Corpo Sala
*  ****/

	CDS_tpCondRet CDS_GetPredioCorpoSala( char * predio, char * cod )
	{
		SAL_tpSala * s ;
		s = CDS_BuscaCodCorpoSala( cod ) ;

		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;

		} else
		{
			SAL_getPredio ( s,predio ) ;
			return CDS_CondRetOK ;
		} /* if */
	
	} /* Fim funcao: CDS &Get Predio Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Get Andar Corpo Sala
*  ****/

	CDS_tpCondRet CDS_GetAndarCorpoSala( int * andar, char * cod )
	{
		SAL_tpSala * s ;
		s = CDS_BuscaCodCorpoSala( cod ) ;
		
		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;

		} else
		{
			SAL_getAndar ( s, andar ) ;
			return CDS_CondRetOK ;
		} /* if */

	} /* Fim funcao: CDS &Get Andar Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Exibe Disponibilidade Corpo Sala
*  ****/

	CDS_tpCondRet CDS_ExibeDisponibilidadeCorpoSala( char * cod )
	{
		SAL_tpSala * s ;
		s = CDS_BuscaCodCorpoSala( cod ) ;

		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;
		} else
		{
			SAL_printDisponibilidade( s ) ;
			return CDS_CondRetOK ; 
		} /* if */

	} /* Fim funcao: CDS &Exibe Disponibilidade Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Busca Disponibilidade Corpo Sala
*  ****/

	SAL_tpSala * CDS_BuscaDispoCorpoSala( int dia, int horini, int horfim, int qtd, int lab )
	{
    
		unsigned int i = 0, size ;
		SAL_tpSala  * s = NULL ;
		int elab ;
		int maxalu ;
		list_size( CorpoS->Sala, &size ) ;
		first( CorpoS->Sala ) ;

		for ( i = 0;i < size; i++ )
		{
			get_val_cursor( CorpoS->Sala, ( void ** ) &s ) ;
			if ( SAL_getHorarioNoDia( s, dia, horini, horfim ) == SAL_CondRetOK )
			{
				SAL_getELaboratorio ( s, &elab ) ;
				if ( elab == lab )
				{
					SAL_getMaxAlunos( s, &maxalu ) ;
					if( maxalu >= qtd )
					{
						return s ;
					} /* if */
				} /* if */
			} /* if */
        
			next( CorpoS->Sala ) ; 
		} /* for */
    
		printf( "Sala nao disponivel ou inexistente\n" ) ;
		return NULL ;
    
	} /* Fim funcao: CDS &Busca Disponibilidade Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Reserva Sala
*  ****/

	CDS_tpCondRet CDS_ReservaSala( int dia, int horini, int horfim, int qtd, int lab )
	{
		int a = -1 ; 
		SAL_tpSala  * s =  NULL ;
		s = CDS_BuscaDispoCorpoSala( dia,  horini,  horfim, qtd, lab ) ;

		if (s == NULL)
		{
			return CDS_CondRetSalaNaoCadastrada ;
		} else
		{
			a = SAL_reservaSala( s, dia, horini, horfim ) ;
			if( a == SAL_CondRetOK )
			{
				SAL_printSala( s ) ;
				printf( "Sala Reservada Com Sucesso\n" ) ;
			} /* if */

			return CDS_CondRetOK ;
		} /* if */
        
	}/* Fim funcao: CDS &Reserva Sala */

/********** Fim do modulo de implementacao: CDS Corpo de Salas **********/