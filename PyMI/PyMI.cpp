// PyMI.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "PyMI.h"
#include "Application.h"
#include "Session.h"
#include "Class.h"
#include "Operation.h"
#include "Instance.h"
#include "Serializer.h"

#include <datetime.h>

PyObject *PyMIError;

static PyMethodDef mi_methods[] = {
    { NULL, NULL, 0, NULL }  /* Sentinel */
};

#ifdef IS_PY3K
static PyModuleDef mimodule = {
    PyModuleDef_HEAD_INIT,
    "mi",
    "Management Infrastructure API module.",
    -1,
    mi_methods
};
#endif

PyObject* initmi(void)
{
    PyDateTime_IMPORT;

    PyObject* m = NULL;

    ApplicationType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&ApplicationType) < 0)
        return NULL;

    SessionType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&SessionType) < 0)
        return NULL;

    ClassType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&ClassType) < 0)
        return NULL;

    InstanceType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&InstanceType) < 0)
        return NULL;

    OperationType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&OperationType) < 0)
        return NULL;

    SerializerType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&SerializerType) < 0)
        return NULL;

#ifdef IS_PY3K
    m = PyModule_Create(&mimodule);
    if (m == NULL)
        return NULL;
#else
    m = Py_InitModule3("mi", mi_methods, "MI module.");
    if (m == NULL)
        return NULL;
#endif

    Py_INCREF(&ApplicationType);
    PyModule_AddObject(m, "Application", (PyObject*)&ApplicationType);

    Py_INCREF(&SessionType);
    PyModule_AddObject(m, "Session", (PyObject*)&SessionType);

    Py_INCREF(&ClassType);
    PyModule_AddObject(m, "Class", (PyObject*)&ClassType);

    Py_INCREF(&InstanceType);
    PyModule_AddObject(m, "Instance", (PyObject*)&InstanceType);

    Py_INCREF(&OperationType);
    PyModule_AddObject(m, "Operation", (PyObject*)&OperationType);

    Py_INCREF(&SerializerType);
    PyModule_AddObject(m, "Serializer", (PyObject*)&SerializerType);

    PyMIError = PyErr_NewException("PyMI.error", NULL, NULL);
    Py_INCREF(PyMIError);
    PyModule_AddObject(m, "error", PyMIError);

    PyObject_SetAttrString(m, "PROTOCOL_WINRM", PyUnicode_FromString("WINRM"));
    PyObject_SetAttrString(m, "PROTOCOL_WMIDCOM", PyUnicode_FromString("WMIDCOM"));

    return m;
}

PyMODINIT_FUNC PyInit_mi(void)
{
    PyObject* m = initmi();
#ifdef IS_PY3K
    return m;
#endif
}
