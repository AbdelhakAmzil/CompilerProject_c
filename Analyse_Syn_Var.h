void Analyse_Syn_Var(File *F){
    FILE *F2,*F3;
    F2=fopen("programme.txt","r");
    F3=fopen("erreur lexical.txt","a");
    F=defiler(F);
    if(strcmp(F->debut->mot,"v")==0){
        F=defiler(F);
        labelv:
        if(strcmp(F->debut->mot,":")==0){
            F=defiler(F);
            labell:
            if(strcmp(F->debut->mot,"entier")==0){
                F=defiler(F);
                labelll:
                if(strcmp(F->debut->mot,";")==0){
                    F=defiler(F);
                    if(F->debut!=NULL){ fputs("\nerreur de syntaxe : aucune caractere ne doit etre apres ;",F3); exit(1);}
                }
                else{ fputs("\nerreur de syntaxe : instruction doit terminer par ;",F3); }
            }
            else{ fputs("\nerreur de syntaxe : la declaration de variable entier",F3); goto labelll;}
        }
        else{ fputs("\nerreur de syntaxe : absence d'un ':' dans l'intruction",F3); goto labell;}
    }
    else { fputs("\nerreur de syntaxe : v non declare",F3); goto labelv;}
    fclose(F2);
    fclose(F3);
}
