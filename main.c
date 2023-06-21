#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "definition.h"
#include "comparFile.h"
#include "Analyse_lix.h"
#include "convertToList.h"
#include "Analyse_Syn_Var.h"
#include "Analyse_Syn_Ecrire.h"
#include "Analyse_Syn_Lire.h"
#include "Analyse_Syn_Deb.h"
#include "Analyse_Syn_Si.h"
#include "Analyse_Syn_Sinon.h"
#include "Analyse_Syn_fin.h"
#include "Analyse_Syn.h"


int main(){
    Analyse_lix();
    Analyse_Syn();
    return 0;
}
/*

                else if(strcmp(F->debut->mot,"fin")==0){
                F=defiler(F);
                if(F->debut!=NULL) fputs("\nerreur de syntaxe : c'est la fin d'algorithme",F3);
                }
*/
