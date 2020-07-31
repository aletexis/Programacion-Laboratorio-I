
int controller_loadFromText(char* path, LinkedList* list);
int controller_loadFromBinary(char* path, LinkedList* list);

int controller_add(LinkedList* list);
int controller_edit(LinkedList* list);
int controller_remove(LinkedList* list);
int controller_list(LinkedList* list);
int controller_sortMenu(LinkedList* list);
int controller_sortParam(LinkedList* list, int sortBy, int order);

int controller_saveAsText(char* path, LinkedList* list);
int controller_saveAsBinary(char* path, LinkedList* list);

int controller_country_findOne(LinkedList* list, int id, int* index);

int controller_filterBySuccess(void* pac);
int controller_filterByFailure(void* pac);

int controller_paisConMasMuertos(LinkedList* list);





