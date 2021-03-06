/**************************************************************************
**   Author: Priyanshu Singh
**   handle: tgamerz
**   Date:   16/08/2015
**
**   Copyright (c) 2015 Priyanshu Singh
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
** DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
** OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
** OR OTHER DEALINGS IN THE SOFTWARE.
**************************************************************************/

#include "cgsquare.h"

CGSquare::CGSquare()
{

}

CGSquare::~CGSquare()
{

}



void CGSquare::init()
{
    glGenBuffers(1, &vboID);
    glGenVertexArrays(1, &vaoID);
}

void CGSquare::update()
{
    QPointF center = (startPoint + endPoint) * 0.5f;
    QPointF extent = (startPoint - endPoint) * 0.5f;

    vertices[0] = glm::vec3(center.x() - extent.x(), center.y() - extent.y(),0.0f);
    vertices[1] = glm::vec3(center.x() - extent.x(), center.y() + extent.y(),0.0f);
    vertices[2] = glm::vec3(center.x() + extent.x(), center.y() + extent.y(),0.0f);
    vertices[3] = glm::vec3(center.x() + extent.x(), center.y() - extent.y(),0.0f);

    //bind vbo
    glBindBuffer(GL_ARRAY_BUFFER,vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
    //unbind vbo
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //bind vao
    glBindVertexArray(vaoID);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    //unbind vao
    glBindVertexArray(0);

    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void CGSquare::draw()
{
    if(isActive()){
        update();
    }
    //bind vao
    glBindVertexArray(vaoID);
    if(!isActive() && isFilled()){
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }else{
        glDrawArrays(GL_LINE_LOOP, 0, 4);
    }
    //unbind vao
    glBindVertexArray(0);
}
