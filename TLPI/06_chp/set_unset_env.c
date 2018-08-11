#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <malloc.h>
#include <string.h>

extern char **environ;

int setenv(const char* env_name, const char* env_val, int overwrite)
{
    char* pNewEnvEntry;
    char** ppEnvEntry;

    if (env_name == NULL || env_name[0] == '\0') {
        errno = EINVAL;
        return -1;
    }

    if (strchr(env_name, '=') != NULL) {
        errno = EINVAL;
        return -1;
    }

    /*search for any entry with name env_name*/
    for (ppEnvEntry = environ; *ppEnvEntry != NULL; ppEnvEntry++ ) {
        if (strncmp(*ppEnvEntry, env_name, strlen(env_name)) == 0 && *ppEnvEntry[strlen(env_name)] == '=') {
            if (overwrite == 0)
                return 0;
            break;
        }
    }

    /*add new entry + set pEnvEntry the size of which fits {env_name}={env_name}]0*/
    pNewEnvEntry =(char*) malloc(strlen(env_name)+strlen(env_val)+2);
    sprintf(pNewEnvEntry, "%s=%s", env_name, env_val);
    *ppEnvEntry = pNewEnvEntry;
    *(++ppEnvEntry) = NULL;
    return 0;
}

int unsetenv(const char* env_name)
{
    char** ppEntryToMove;
    char** ppTargetLocation;

    /*validate input*/
    if (env_name == NULL || env_name[0]=='\0') {
        errno = EINVAL;
        return -1;
    }

    if (strchr(env_name, '=') != NULL) {
        errno = EINVAL;
        return -1;
    } 

    for (ppTargetLocation = environ; *ppTargetLocation != NULL; ppTargetLocation++) {
        if (strncmp(*ppTargetLocation, env_name, strlen(env_name)) == 0 && *ppTargetLocation[strlen(env_name)] == '=') {
            break;
        }
    }

    if (ppTargetLocation == NULL) {
        return 0;//not found
    } else if (*(ppTargetLocation +1) == NULL){
        ppTargetLocation = NULL;
    } else {
        ppEntryToMove = ppTargetLocation;
        while (*(++ppEntryToMove + 1)!=NULL);
        ppTargetLocation = ppEntryToMove;
        ppEntryToMove = NULL;
    }
    return 0;
}

int main(int argc, char** argv)
{
    return 0;
}
