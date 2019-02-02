/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/

#ifndef QML_ZHTTP_REQUEST_H
#define QML_ZHTTP_REQUEST_H

#include <QtQml>

#include <czmq.h>
#include "qml_czmq_plugin.h"


class QmlZhttpRequest : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isNULL READ isNULL)

public:
    zhttp_request_t *self;

    QmlZhttpRequest() { self = NULL; }
    bool isNULL() { return self == NULL; }

    static QObject* qmlAttachedProperties(QObject* object); // defined in QmlZhttpRequest.cpp

public slots:
    //  Receive a new request from zhttp_server.
    //  Return the underlying connection if successful, to be used when calling zhttp_response_send.
    QmlZhttpServerConnection *recv (QmlZsock *sock);

    //  Send a request to zhttp_client.
    //  Url and the request path will be concatenated.
    //  This behavior is useful for url rewrite and reverse proxy.
    //
    //  Send also allow two user provided arguments which will be returned with the response.
    //  The reason for two, is to be able to pass around the server connection when forwarding requests or both a callback function and an arg.
    int send (QmlZhttpClient *client, int timeout, void *arg, void *arg2);

    //  Get the request method
    const QString method ();

    //  Set the request method
    void setMethod (const QString &method);

    //  Get the request url.
    //  When receiving a request from http server this is only the path part of the url.
    const QString url ();

    //  Set the request url
    //  When sending a request to http client this should be full url.
    void setUrl (const QString &url);

    //  Get the request content type
    const QString contentType ();

    //  Set the request content type
    void setContentType (const QString &contentType);

    //  Get the content length of the request
    size_t contentLength ();

    //  Get the headers of the request
    QmlZhash *headers ();

    //  Get the content of the request.
    const QString content ();

    //  Get the content of the request.
    QString getContent ();

    //  Set the content of the request.
    //  Content must by dynamically allocated string.
    //  Takes ownership of the content.
    void setContent (QString content);

    //  Set the content of the request..
    //  The content is assumed to be constant-memory and will therefore not be copied or deallocated in any way.
    void setContentConst (const QString &content);

    //  Set the content to NULL
    void resetContent ();

    //  Match the path of the request.
    //  Support wildcards with '%s' symbol inside the match string.
    //  Matching wildcars is until the next '/', '?' or '\0'.
    //  On successful match the variadic arguments will be filled with the matching strings.
    //  On successful match the method is modifying the url field and break it into substrings.
    //  If you need to use the url, do it before matching or take a copy.
    //
    //  User must not free the variadic arguments as they are part of the url.
    //
    //  To use the percent symbol, just double it, e.g "%%something".
    //
    //  Example:
    //  if (zhttp_request_match (request, "POST", "/send/%s/%s", &name, &id))
    bool match (const QString &method, const QString &match);
};

class QmlZhttpRequestAttached : public QObject
{
    Q_OBJECT
    QObject* m_attached;

public:
    QmlZhttpRequestAttached (QObject* attached) {
        Q_UNUSED (attached);
    };

public slots:
    //  Self test of this class.
    void test (bool verbose);

    //  Create a new http request.
    QmlZhttpRequest *construct ();

    //  Destroy an http request.
    void destruct (QmlZhttpRequest *qmlSelf);
};


QML_DECLARE_TYPEINFO(QmlZhttpRequest, QML_HAS_ATTACHED_PROPERTIES)

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
