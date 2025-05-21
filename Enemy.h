#pragma once

//#indlude <Windows.h>
//na linux go pisah za tva ne bachka
#include <bits/stdc++.h>

class Enemy
{
protected:
    int x,y;
    int direction;
    int speed;
public:
    Enemy() : x(0), y(0), direction(0), speed(1) {}

    Enemy(int X, int Y, int Dir, int Speed);

    Enemy(const Enemy&);

    Enemy(Enemy&& other) noexcept;

    Enemy& operator=(const Enemy&);

    Enemy& operator=(Enemy&&);

    virtual void update();
    
    virtual void render(HDC hdc) const;


};

//shte se razberete za razlikite v enemytata i shte gi dopishem
class EnemyType1 : public Enemy
{
private:
    COLORREF color;
public: 
    EnemyType1() : Enemy(), color(RGB(255, 0, 0)) {}

    EnemyType1(int X, int Y, int Dir, int Speed, COLORREF Color);

    EnemyType1(const Enemy&);

    EnemyType1(Enemy&& other) noexcept;

    EnemyType1& operator=(const Enemy&);

    EnemyType1& operator=(Enemy&&);

    void render() const;    

};

class EnemyType1 : public Enemy
{
private:
    COLORREF color;
public: 
    EnemyType2() : Enemy(), color(RGB(255, 0, 0)) {}

    EnemyType2(int X, int Y, int Dir, int Speed, COLORREF Color);

    EnemyType2(const Enemy&);

    EnemyType2(Enemy&& other) noexcept;

    EnemyType2& operator=(const Enemy&);

    EnemyType2& operator=(Enemy&&);

    void render() const;    

};

class EnemyType3 : public Enemy
{
private:
    COLORREF color;
public: 
    EnemyType3() : Enemy(), color(RGB(255, 0, 0)) {}

    EnemyType3(int X, int Y, int Dir, int Speed, COLORREF Color);

    EnemyType3(const Enemy&);

    EnemyType3(Enemy&& other) noexcept;

    EnemyType3& operator=(const Enemy&);

    EnemyType3& operator=(Enemy&&);

    void render() const;    

};

class EnemyType4 : public Enemy
{
private:
    COLORREF color;
public: 
    EnemyType4() : Enemy(), color(RGB(255, 0, 0)) {}

    EnemyType4(int X, int Y, int Dir, int Speed, COLORREF Color);

    EnemyType4(const Enemy&);

    EnemyType4(Enemy&& other) noexcept;

    EnemyType4& operator=(const Enemy&);

    EnemyType4& operator=(Enemy&&);

    void render() const;    

};