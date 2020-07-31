
int controller_loadFromText(char* path, LinkedList* list);
int controller_loadFromBinary(char* path, LinkedList* list);


int controller_list(LinkedList* list);
int controller_sortParam(LinkedList* list, int sortBy, int order);

int controller_saveAsText(char* path, LinkedList* list);
int controller_saveAsBinary(char* path, LinkedList* list);


int controller_filterBMX(void* element);
int controller_filterPlayera(void* element);
int controller_filterMTB(void* element);
int controller_filterPaseo(void* element);






