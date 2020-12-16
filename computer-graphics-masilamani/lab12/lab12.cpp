#include<bits/stdc++.h>
#include<GL/glut.h>
#define ld long double
#define PI 3.14159265
#define deg *0.0174532925//(PI/180=0.0174532925)
using namespace std;

int window_size[]={600,800};//{height,width}
vector<ld> rgb(int r, int g, int b){
    vector<ld> f;
    f.push_back((double)r/255.0);
    f.push_back((double)g/255.0);
    f.push_back((double)b/255.0);
    return f;
}
void init(){
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);  
    glFlush();
}
void Point(vector<ld> color,vector<pair<ld,ld>> array,ld point_size=5){
    glPointSize(point_size);
    glBegin(GL_POINTS);
        glColor3f(color[0],color[1], color[2]);
        for(int i=0 ; i<array.size(); ++i) glVertex2f(array[i].first,array[i].second);
    glEnd();
}
void ellipse(vector<ld> color,vector<ld> origin, ld a,ld b ,ld precision=0.8,ld thick=5){
    for(ld i=0;i<360;i+=precision){
        Point(color,{
            {(origin[0]+a*cos(i deg)),(origin[1]+b*sin(i deg))}
        },thick);
    }
}
void circle(vector<ld> color,vector<ld> origin, ld r ,ld precision=0.8,ld thick=5){
    for(ld i=0;i<360;i+=precision){
        Point(color,{
            {(origin[0]+r*cos(i deg)),(origin[1]+r*sin(i deg))}
        },thick);
    }
}
void sphere(vector<ld> color,vector<ld> origin,ld radius,int vlines=3,int hlines=3,ld precision =0.8,ld thickness=2.5){
    circle(color,origin,radius,precision,thickness);//circumfrence
    ld temp;
    //vertical lines
    temp = (2*radius)/(vlines+1);
    for(ld i=temp/2;i<radius;i+=temp) ellipse(color,origin,i,radius,precision,thickness);
    //horizontal lines
    temp=(2*radius)/(hlines+1);
    for(ld y=temp-radius;y<radius;y+=temp){
        ld x=sqrt(radius*radius-(y*y));
        ellipse(color,{origin[0],origin[1]+y},x,temp/3,precision,thickness);
    }
}
void display(void){
    init();
    ld earth_orbit_a=350,earth_orbit_b=50;
    ld moon_orbit_a=100,moon_orbit_b=20;
    ld sun_radius=100,earth_radius=50,moon_radius=20;
    ld rotation_earth_wrt_sun=10;
    ld rate_of_rotation_moon_wrt_earth=3;
    ld earth_to_moon_angle=0;
    for(ld rot=0;rot<360*rotation_earth_wrt_sun;rot+=1/rate_of_rotation_moon_wrt_earth){
        ld x=(earth_orbit_a*cos(rot deg)),y=(earth_orbit_b*sin(rot deg));
        ld sun_to_earth_angle=(int)rot%360;
        
        glClear(GL_COLOR_BUFFER_BIT);
        ellipse(rgb(100,100,100),{0,0},earth_orbit_a,earth_orbit_b,0.8,3);//earth orbit
        ld moon_vline = 2, moon_hline=2, moon_precision = 0.8, moon_thickness = 1.5;
        sphere(rgb(255,255,255),{(x+moon_orbit_a*cos(earth_to_moon_angle deg)),(y+moon_orbit_b*sin(earth_to_moon_angle deg))},moon_radius,moon_vline,moon_hline,moon_precision,moon_thickness);//moon
        sphere(rgb(20,20,255),{x,y},earth_radius);//earth
        earth_to_moon_angle+=rate_of_rotation_moon_wrt_earth;
        earth_to_moon_angle=(int)earth_to_moon_angle%360;
        sphere(rgb(207, 182, 0),{0,0},sun_radius,5,5,0.8,1.5);//sun
        glFlush();
    }
}
int main(int argc,char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(window_size[1]/*width*/,window_size[0]/*height*/);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Solar System - CED17I029");
    gluOrtho2D(-window_size[1]/2,window_size[1]/2,-window_size[0]/2,window_size[0]/2);//origin cente
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}