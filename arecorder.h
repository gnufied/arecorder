#ifndef ARECORDER_H
#define ARECORDER_H

#include <QObject>
#include <QAudioRecorder>
#include <QString>

class ARecorder : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool recording READ recording NOTIFY recordingChanged)
    Q_PROPERTY(QString fileName READ fileName)
public:
    explicit ARecorder(QObject *parent = 0);
    const bool &recording() const;
    const QString &fileName() const;

signals:
    void recordingChanged();

public slots:
    void record();
    void stop();
private:
    bool b_recording;
    QAudioRecorder *q_audioRecorder;
    QString b_fileName;
};

#endif // ARECORDER_H
