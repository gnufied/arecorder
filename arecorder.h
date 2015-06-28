#ifndef ARECORDER_H
#define ARECORDER_H

#include <QObject>
#include <QAudioRecorder>

class ARecorder : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool recording READ recording NOTIFY recordingChanged)
public:
    explicit ARecorder(QObject *parent = 0);
    const bool &recording() const;

signals:
    void recordingChanged();

public slots:
    void record();
    void stop();
private:
    bool b_recording;
    QAudioRecorder *q_audioRecorder;
};

#endif // ARECORDER_H
