#ifndef DAKOTA_ENGINE_H
#define DAKOTA_ENGINE_H

/* *****************************************************************************
Copyright (c) 2016-2017, The Regents of the University of California (Regents).
All rights reserved.

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the FreeBSD Project.

REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED HEREUNDER IS 
PROVIDED "AS IS". REGENTS HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, 
UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

*************************************************************************** */

// Written: fmckenna

#include <UQ_Engine.h>

class QComboBox;
class QLabel;
class QStackedWidget;
class QCheckBox;
class UQ_Results;

class DakotaEngine : public UQ_Engine
{
    Q_OBJECT
public:
  explicit DakotaEngine(UQ_EngineType type, QWidget *parent = 0);
    virtual ~DakotaEngine();

    int getMaxNumParallelTasks(void);
    bool outputToJSON(QJsonObject &jsonObject);
    bool inputFromJSON(QJsonObject &jsonObject);
    bool outputAppDataToJSON(QJsonObject &jsonObject);
    bool inputAppDataFromJSON(QJsonObject &jsonObject);
    void setRV_Defaults(void);
    UQ_Results *getResults(void);

    QString getProcessingScript();
    QString getMethodName();
    bool copyFiles(QString &fileDir);
    bool fixMethod(QString Methodname);
signals:
    void onUQ_EngineChanged(QString);
    void onUQ_MethodUpdated(QString);
    void onNumModelsChanged(int newNum);

public slots:
    void engineSelectionChanged(const QString &arg1);
    void numModelsChanged(int newNum);

private:
   QLabel * label;
   QComboBox   *theEngineSelectionBox;
   QStackedWidget *theStackedWidget;
   QCheckBox *parallelCheckBox, *removeWorkdirCheckBox;

   UQ_Engine *theCurrentEngine;
   UQ_Engine *theSamplingEngine;
   UQ_Engine *theReliabilityEngine;
   UQ_Engine *theCalibrationEngine;
   UQ_Engine *theBayesianCalibrationEngine;
   UQ_Engine *theSensitivityEngine;
   UQ_Engine *theOptimizationEngine;
};

#endif // DAKOTA_ENGINE_H
