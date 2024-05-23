/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** dialogues_parser.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/pirate_quest.h"

static dialogue_interlocutor_t get_speaker_enum_bis(const char *speaker)
{
    if (strcmp(speaker, "JULIE") == 0)
        return JULIE;
    if (strcmp(speaker, "OTIS") == 0)
        return OTIS;
    if (strcmp(speaker, "GROGNON") == 0)
        return GROGNON;
    if (strcmp(speaker, "GUARDE") == 0)
        return GUARDE;
    return UNKNOWN;
}

static dialogue_interlocutor_t get_speaker_enum(const char *speaker)
{
    if (strcmp(speaker, "ME") == 0)
        return ME;
    if (strcmp(speaker, "ANA") == 0)
        return ANA;
    if (strcmp(speaker, "FRANCK") == 0)
        return FRANCK;
    if (strcmp(speaker, "TUTO") == 0)
        return TUTO;
    if (strcmp(speaker, "MAYOR") == 0)
        return MAYOR;
    if (strcmp(speaker, "SANDRINE") == 0)
        return SANDRINE;
    if (strcmp(speaker, "MICHEL") == 0)
        return MICHEL;
    if (strcmp(speaker, "DOUGLAS") == 0)
        return DOUGLAS;
    if (strcmp(speaker, "MARIE") == 0)
        return MARIE;
    return get_speaker_enum_bis(speaker);
}

static dialogue_t *realloc_dialogues(dialogue_t *dialogues, int dialogue_count)
{
    dialogues = realloc(dialogues, sizeof(dialogue_t) * (dialogue_count + 1));
    if (!dialogues) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return dialogues;
}

static void parse_line(dialogue_t *dialogues, int dialogue_count, char *line)
{
    char speaker[50];
    unsigned int time;
    char dialogue_text[500];
    size_t len;

    if (sscanf(line, "[%49[^]]]=>%u\n", speaker, &time) == 2) {
        if (fgets(dialogue_text, sizeof(dialogue_text), dialogues->file)) {
            dialogues[dialogue_count].speaker = get_speaker_enum(speaker);
            dialogues[dialogue_count].time = time;
            len = strlen(dialogue_text);
            dialogues[dialogue_count].content =
                malloc(sizeof(sfUint32) * (len + 1));
            utf8_to_32(dialogue_text, dialogue_text + len + 1,
                dialogues[dialogue_count].content);
        }
    }
}

dialogue_t *parse_dialogue_file(const char *file_path, int *dialogue_count)
{
    FILE *file = fopen(file_path, "r");
    char line[256];
    dialogue_t *dialogues = NULL;

    if (!file)
        return NULL;
    *dialogue_count = 0;
    while (fgets(line, sizeof(line), file)) {
        if (line[0] != '[')
            continue;
        dialogues = realloc_dialogues(dialogues, *dialogue_count);
        dialogues[*dialogue_count].file = file;
        parse_line(dialogues, *dialogue_count, line);
        (*dialogue_count)++;
    }
    fclose(file);
    return dialogues;
}

void free_dialogues(dialogue_t *dialogues, int dialogue_count)
{
    for (int i = 0; i < dialogue_count; i++)
        free(dialogues[i].content);
    free(dialogues);
}
