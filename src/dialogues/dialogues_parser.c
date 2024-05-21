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

static dialogue_interlocutor_t get_speaker_enum(const char *speaker)
{
    if (strcmp(speaker, "ME") == 0)
        return ME;
    if (strcmp(speaker, "ANA") == 0)
        return ANA;
    if (strcmp(speaker, "FRANCK") == 0)
        return FRANCK;
    return UNKNOWN;
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

static void parse_line(dialogue_t *dialogues, int dialogue_count, char *line,
    char *content)
{
    char speaker[50];
    int time;
    char dialogue_text[200];

    if (sscanf(line, "[%49[^]]]=>%d\n", speaker, &time) == 2) {
        if (fgets(dialogue_text, sizeof(dialogue_text), dialogues->file)) {
            dialogues[dialogue_count].speaker = get_speaker_enum(speaker);
            dialogues[dialogue_count].time = time;
            dialogues[dialogue_count].content = strdup(dialogue_text);
        }
    }
}

dialogue_t *parse_dialogue_file(const char *file_path, int *dialogue_count)
{
    FILE *file = fopen(file_path, "r");
    char line[256];
    dialogue_t *dialogues = NULL;
    char content[200];

    if (!file)
        return NULL;
    *dialogue_count = 0;
    while (fgets(line, sizeof(line), file)) {
        if (line[0] != '[')
            continue;
        dialogues = realloc_dialogues(dialogues, *dialogue_count);
        dialogues[*dialogue_count].file = file;
        parse_line(dialogues, *dialogue_count, line, content);
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
