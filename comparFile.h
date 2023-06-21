int comparFile(File *P,char *mot){
    Element* temp;
    temp=P->debut;
    while(temp){
        if(strcmp(temp->mot,mot)==0){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
