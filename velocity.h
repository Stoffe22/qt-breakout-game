#ifndef VELOCITY_H
#define VELOCITY_H


struct Velocity
{
    Velocity();
    int vx;
    int vy;

    void setVelocity(int velX, int velY) {vx = velX; vy = velY; }
};

#endif // VELOCITY_H
