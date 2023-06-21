void Analyse_Syn_Ecrire(File *F){
    FILE *F2,*F3;
    F2=fopen("programme.txt","r");
    F3=fopen("erreur lexical.txt","a");
    F=defiler(F);
    if(strcmp(F->debut->mot,"(")==0){
        F=defiler(F);
        label:
        if(strcmp(F->debut->mot,"v")==0){
            F=defiler(F);
            label1:
            if(strcmp(F->debut->mot,")")==0){
                F=defiler(F);
                label2:
                if(strcmp(F->debut->mot,";")==0){
                    F=defiler(F);
                    label3:
                    if(F->debut!=NULL) fputs("\nerreur de syntaxe : aucune caractere ne doit etre apres ;",F3);
                }
                else{ fputs("\nerreur de syntaxe : instruction doit se terminer par ';'",F3); goto label3;}
            }
            else{ fputs("\nerreur de syntaxe : instruction doit se terminer par ')'",F3); goto label2;}
        }
        else{ fputs("\nerreur de syntaxe : instruction non formulee une caractere entre parenthese",F3); goto label1;}
    }
    else{ fputs("\nerreur de syntaxe : ecriture doit commencer par '('",F3); goto label;}
    fclose(F2);
    fclose(F3);
}
