void Analyse_Syn_Deb(File *F){
    FILE *F2,*F3;
    F2=fopen("programme.txt","r");
    F3=fopen("erreur lexical.txt","a");
    F=defiler(F);
    if(strcmp(F->debut->mot,";")==0){
        F=defiler(F);
        label4:
        if(F->debut!=NULL) fputs("\nerreur de syntaxe : aucune caractere ne doit etre apres ;",F3);
    }
    else{ fputs("\nerreur de syntaxe : instruction doit se terminer par ';'",F3); goto label4;}
    fclose(F2);
    fclose(F3);
}
