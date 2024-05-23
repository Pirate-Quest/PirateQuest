/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** dialogues_registry.c
*/

#include "../../include/pirate_quest.h"

const interlocutor_builder_t interlocutors[] = {
    {
        .interlocutor = UNKNOWN,
        .name = "???",
        .file_path = "assets/sprites/me.png",
        .scale = 2.5,
        .origin = (sfVector2f){0.0, 0.0},
        .size = (sfVector2f){32.0, 64.0}
    },
    {
        .interlocutor = ME,
        .name = "Me",
        .file_path = "assets/sprites/me.png",
        .scale = 2.5,
        .origin = (sfVector2f){0.0, 0.0},
        .size = (sfVector2f){32.0, 64.0}
    },
    {
        .interlocutor = FRANCK,
        .name = "Franck",
        .file_path = "assets/sprites/franck.png",
        .scale = 2.5,
        .origin = (sfVector2f){100.0, 100.0},
        .size = (sfVector2f){32.0, 64.0}
    },
    {
        .interlocutor = ANA,
        .name = "Ana",
        .file_path = "assets/sprites/ana.png",
        .scale = 2.5,
        .origin = (sfVector2f){100.0, 100.0},
        .size = (sfVector2f){32.0, 64.0}
    },
    {
        .interlocutor = ASTORA,
        .name = "Solaire d'Astora",
        .file_path = "assets/sprites/solaire.png",
        .scale = 0.30,
        .origin = (sfVector2f){100.0, 0.0},
        .size = (sfVector2f){357.0, 699.0}
    },
    {
        .interlocutor = TUTO,
        .name = "Seigneur des pirates",
        .file_path = "assets/sprites/tuto.png",
        .scale = 0.40,
        .origin = (sfVector2f){100.0, 100.0},
        .size = (sfVector2f){300.0, 383.0}
    },
    {
        .interlocutor = MAYOR,
        .name = "Maire de la ville",
        .file_path = "assets/sprites/mayor.png",
        .scale = 0.40,
        .origin = (sfVector2f){100.0, 100.0},
        .size = (sfVector2f){300.0, 362.0}
    },
    {
        .interlocutor = SANDRINE,
        .name = "Sandrine",
        .file_path = "assets/sprites/png_9.png",
        .scale = 2,
        .origin = (sfVector2f){100.0, 0.0},
        .size = (sfVector2f){60.0, 70.0}
    },
    {
        .interlocutor = MICHEL,
        .name = "Michel",
        .file_path = "assets/sprites/png_2.png",
        .scale = 2,
        .origin = (sfVector2f){100.0, 0.0},
        .size = (sfVector2f){60.0, 70.0}
    },
    {
        .interlocutor = DOUGLAS,
        .name = "Douglas",
        .file_path = "assets/sprites/farmer_2.png",
        .scale = 0.2,
        .origin = (sfVector2f){100.0, 0.0},
        .size = (sfVector2f){475.0, 525.0}
    },
    {
        .interlocutor = MARIE,
        .name = "Marie",
        .file_path = "assets/sprites/png_8.png",
        .scale = 2,
        .origin = (sfVector2f){100.0, 0.0},
        .size = (sfVector2f){60.0, 70.0}
    },
    {
        .interlocutor = JULIE,
        .name = "Julie",
        .file_path = "assets/sprites/png_7.png",
        .scale = 2,
        .origin = (sfVector2f){100.0, 0.0},
        .size = (sfVector2f){60.0, 70.0}
    },
    {
        .interlocutor = GROGNON,
        .name = "Client Grognon",
        .file_path = "assets/sprites/png_4.png",
        .scale = 2,
        .origin = (sfVector2f){100.0, 0.0},
        .size = (sfVector2f){60.0, 70.0}
    },
    {
        .interlocutor = OTIS,
        .name = "Otis",
        .file_path = "assets/sprites/png_1.png",
        .scale = 2,
        .origin = (sfVector2f){100.0, 0.0},
        .size = (sfVector2f){60.0, 70.0}
    },
    {
        .interlocutor = GUARDE,
        .name = "Guarde",
        .file_path = "assets/sprites/ds2.png",
        .scale = 0.4,
        .origin = (sfVector2f){100.0, 0.0},
        .size = (sfVector2f){500.0, 500.0}
    },
};

const dialogue_builder_t dialogues[] = {
    {TUTORIAL_1, "assets/dialogues/tutorial_1.dialogue"},
    {FIRST_NPC, "assets/dialogues/png1.dialogue"},
    {COMMAND, "assets/dialogues/tutorial.dialogue"},
    {MAYOR_DG, "assets/dialogues/mayor.dialogue"},
    {SOLO_SWORD, "assets/dialogues/sword.dialogue"},
    {FIRST_WOMEN, "assets/dialogues/women_red_house.dialogue"},
    {MICH, "assets/dialogues/michel.dialogue"},
    {DOUGLA, "assets/dialogues/douglas.dialogue"},
    {MARI, "assets/dialogues/marie.dialogue"},
    {MONO, "assets/dialogues/asterix.dialogue"},
    {GRE, "assets/dialogues/julie.dialogue"},
    {GROGN, "assets/dialogues/grognon.dialogue"},
    {GUARD, "assets/dialogues/guard.dialogue"},
};

const int intrlcutors = sizeof(interlocutors) / sizeof(interlocutor_builder_t);
const int dialogue_count = sizeof(dialogues) / sizeof(dialogue_builder_t);

static void set_interlocutor_texture(pirate_quest_t *game, int i)
{
    game->interlocutors[i].texture = sfTexture_createFromFile(
        interlocutors[i].file_path, NULL);
    game->interlocutors[i].sprite = sfSprite_create();
    sfSprite_setTexture(game->interlocutors[i].sprite,
        game->interlocutors[i].texture, sfTrue);
}

static void set_interlocutor_position(pirate_quest_t *game, int i)
{
    if (interlocutors[i].interlocutor == ME)
        sfSprite_setPosition(game->interlocutors[i].sprite,
            (sfVector2f){0.0, get_resolution(game).height -
            (interlocutors[i].size.y * interlocutors[i].scale
            * game->camera->zoom)}
        );
    else
        sfSprite_setPosition(game->interlocutors[i].sprite,
            (sfVector2f){get_resolution(game).width - (interlocutors[i].size.x
            * interlocutors[i].scale * game->camera->zoom),
            get_resolution(game).height - (interlocutors[i].size.y
            * interlocutors[i].scale * game->camera->zoom)}
        );
}

static void set_interlocutor_scale(pirate_quest_t *game, int i)
{
    sfSprite_setScale(game->interlocutors[i].sprite, (sfVector2f){
            interlocutors[i].scale * game->camera->zoom,
            interlocutors[i].scale * game->camera->zoom
    });
}

static void set_interlocutor_name(pirate_quest_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->interlocutors[i].sprite);
    sfFloatRect rect;

    game->interlocutors[i].name_text = sfText_create();
    sfText_setString(game->interlocutors[i].name_text, interlocutors[i].name);
    sfText_setFont(game->interlocutors[i].name_text, game->font);
    sfText_setCharacterSize(game->interlocutors[i].name_text, 20);
    rect = sfText_getGlobalBounds(game->interlocutors[i].name_text);
    sfText_setPosition(game->interlocutors[i].name_text,
        (sfVector2f){pos.x + (interlocutors[i].size.x
        * interlocutors[i].scale * game->camera->zoom) / 2 - rect.width / 2,
        pos.y - 10});
}

static void set_interlocutor_name_bg(pirate_quest_t *game, int i)
{
    sfVector2f pos = sfSprite_getPosition(game->interlocutors[i].sprite);
    sfFloatRect rect = sfText_getGlobalBounds(
        game->interlocutors[i].name_text);

    game->interlocutors[i].name_bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(game->interlocutors[i].name_bg,
        (sfColor){0, 0, 0, 150});
    sfRectangleShape_setSize(game->interlocutors[i].name_bg,
        (sfVector2f){rect.width + 30, rect.height + 30});
    sfRectangleShape_setPosition(game->interlocutors[i].name_bg,
        (sfVector2f){pos.x - 10 + (interlocutors[i].size.x
        * interlocutors[i].scale * game->camera->zoom) / 2 -
        rect.width / 2 - 5, pos.y - 20});
}

void init_interlocutors_registry(pirate_quest_t *game)
{
    game->interlocutors =
        malloc(sizeof(interlocutor_impl_t) * intrlcutors);
    for (int i = 0; i < intrlcutors; i++) {
        game->interlocutors[i].interlocutor = &(interlocutors[i].interlocutor);
        set_interlocutor_texture(game, i);
        set_interlocutor_position(game, i);
        set_interlocutor_scale(game, i);
        set_interlocutor_name(game, i);
        set_interlocutor_name_bg(game, i);
    }
}

void free_interlocutors_registry(pirate_quest_t *game)
{
    for (int i = 0; i < intrlcutors; i++) {
        sfTexture_destroy(game->interlocutors[i].texture);
        sfSprite_destroy(game->interlocutors[i].sprite);
    }
    free(game->interlocutors);
}

void draw_interlocutor(pirate_quest_t *game,
    dialogue_interlocutor_t interlocutor)
{
    for (int i = 0; i < intrlcutors; i++) {
        if (interlocutors[i].interlocutor != interlocutor)
            continue;
        sfRenderWindow_drawSprite(game->window->window,
            game->interlocutors[i].sprite, NULL);
        sfRenderWindow_drawRectangleShape(game->window->window,
            game->interlocutors[i].name_bg, NULL);
        sfRenderWindow_drawText(game->window->window,
            game->interlocutors[i].name_text, NULL);
    }
}

void init_dialogues_registry(pirate_quest_t *game)
{
    game->dialogues =
        malloc(sizeof(dialogue_impl_t) * dialogue_count);
    for (int i = 0; i < dialogue_count; i++) {
        game->dialogues[i].dialogue = dialogues[i].dialogue;
        game->dialogues[i].dialogue_count = 0;
        game->dialogues[i].dialogues = parse_dialogue_file(
            dialogues[i].file_path,
            &game->dialogues[i].dialogue_count
        );
    }
}

void free_dialogues_registry(pirate_quest_t *game)
{
    for (int i = 0; i < dialogue_count; i++) {
        free_dialogues(game->dialogues[i].dialogues,
            game->dialogues[i].dialogue_count);
    }
    free(game->dialogues);
}
