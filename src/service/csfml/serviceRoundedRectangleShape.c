/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceRoundedRectangleShape.c
*/

#include "gradeDe.h"

static sfVector3f drawArcTopLeft(sfConvexShape *roundedRectangle, sfVector3f pointInfo, int radius)
{
    float step = radius / (radius - 1);
    sfVector2f pointPos = {0, 0};

    for (int i = 0; i < radius; i++) {
        pointPos.x += step;
        pointPos.y = sqrt(pow(radius, 2) - pow(radius - pointPos.x, 2));
        sfConvexShape_setPoint(
            roundedRectangle,
            pointInfo.z,
            (sfVector2f){
                pointInfo.x + pointPos.x,
                pointInfo.y - pointPos.y
            }
        );
        pointInfo.z++;
    }

    pointInfo.x += pointPos.x;
    pointInfo.y -= pointPos.y;
    return pointInfo;
}

static sfVector3f drawArcTopRight(sfConvexShape *roundedRectangle, sfVector3f pointInfo, int radius)
{
    float step = radius / (radius - 1);
    sfVector2f pointPos = {0, 0};

    for (int i = 0; i < radius; i++) {
        pointPos.y += step;
        pointPos.x = sqrt(pow(radius, 2) - pow(radius - pointPos.y, 2));
        sfConvexShape_setPoint(
            roundedRectangle,
            pointInfo.z,
            (sfVector2f){
                pointInfo.x + pointPos.x,
                pointInfo.y + pointPos.y
            }
        );
        pointInfo.z++;
    }

    pointInfo.x += pointPos.x;
    pointInfo.y += pointPos.y;
    return pointInfo;
}

static sfVector3f drawArcBottomRight(sfConvexShape *roundedRectangle, sfVector3f pointInfo, int radius)
{
    float step = radius / (radius - 1);
    sfVector2f pointPos = {0, 0};

    for (int i = 0; i < radius; i++) {
        pointPos.x += step;
        pointPos.y = sqrt(pow(radius, 2) - pow(radius - pointPos.x, 2));
        sfConvexShape_setPoint(
            roundedRectangle,
            pointInfo.z,
            (sfVector2f){
                pointInfo.x - pointPos.x,
                pointInfo.y + pointPos.y
            }
        );
        pointInfo.z++;
    }

    pointInfo.x -= pointPos.x;
    pointInfo.y += pointPos.y;
    return pointInfo;
}

static sfVector3f drawArcBottomLeft(sfConvexShape *roundedRectangle, sfVector3f pointInfo, int radius)
{
    float step = radius / (radius - 1);
    sfVector2f pointPos = {0, 0};

    for (int i = 0; i < radius; i++) {
        pointPos.y += step;
        pointPos.x = sqrt(pow(radius, 2) - pow(radius - pointPos.y, 2));
        sfConvexShape_setPoint(
            roundedRectangle,
            pointInfo.z,
            (sfVector2f){
                pointInfo.x - pointPos.x,
                pointInfo.y - pointPos.y
            }
        );
        pointInfo.z++;
    }

    pointInfo.x -= pointPos.x;
    pointInfo.y -= pointPos.y;
    return pointInfo;
}


sfConvexShape *createRoundedRectangle(sfVector3f settings, sfColor color, sfVector2f position)
{
    int width = settings.x; int height = settings.y; int radius = settings.z;
    sfVector2f rectangleBorder = {width - (radius) * 2, height - (radius) * 2};
    sfVector3f pointInfo = {0, 0, 0};
    int borderWidthStep[4] = {rectangleBorder.x, 0, -rectangleBorder.x, 0};
    int borderHeightStep[4] = {0, rectangleBorder.y, 0, -rectangleBorder.y};
    sfVector3f (*drawArc[4])(sfConvexShape *, sfVector3f, int) = {drawArcTopLeft, drawArcTopRight, drawArcBottomRight, drawArcBottomLeft};

    sfConvexShape *roundedRectangle = sfConvexShape_create();
    sfConvexShape_setPointCount(roundedRectangle, (radius + 1) * 4 + 1);
    sfConvexShape_setPoint(roundedRectangle, pointInfo.z, (sfVector2f){pointInfo.x, pointInfo.y}); pointInfo.z++;

    for (int i = 0; i < 4; i++) {
        pointInfo = drawArc[i](roundedRectangle, pointInfo, radius);
        pointInfo.x += borderWidthStep[i];
        pointInfo.y += borderHeightStep[i];
        sfConvexShape_setPoint(roundedRectangle, pointInfo.z, (sfVector2f){pointInfo.x, pointInfo.y}); pointInfo.z++;
    }

    sfConvexShape_setOrigin(roundedRectangle, (sfVector2f){0, -radius});
    sfConvexShape_setPosition(roundedRectangle, position);
    sfConvexShape_setFillColor(roundedRectangle, color);

    return roundedRectangle;
}

void renderRoundedRectangle(sfConvexShape *roundedRectangle)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    sfRenderWindow_drawConvexShape(windowConfig->window, roundedRectangle, NULL);
}
