#pragma once

#include <string>

// TODO: what the fuck
inline static const std::string g_schema = R"({ 
"$schema": "https://json-schema.org/draft/2020-12/schema",

"type" : "object",
"properties" : {
    "points": {
        "type": "array",
            "items" : { "$ref": "#/definitions/geometry/point" }
    },
        "geometry" : {
        "type": "array",
            "items" : {
            "oneOf": [
            { "$ref": "#/definitions/geometry/torus" },
            { "$ref": "#/definitions/geometry/bezierC0" },
            { "$ref": "#/definitions/geometry/bezierC2" },
            { "$ref": "#/definitions/geometry/interpolatedC2" }
            ]
        }
    }
},
"additionalProperties": false,

"definitions" : {

    "normalizedValue": {
        "type": "number",
            "minimum" : 0.0,
            "maximum" : 1.0
    },

        "positiveValue": {
            "type": "number",
                "minimum" : 0.0
        },

            "uint" : {
                "type": "integer",
                    "minimum" : 0
            },

                "float3" : {
                    "type": "object",
                        "properties" : {
                        "x": { "type": "number" },
                            "y" : { "type": "number" },
                            "z" : { "type": "number" }
                    },
                        "required" : ["x", "y", "z"] ,
                        "additionalProperties" : false
                },

                    "uint2": {
                        "type": "object",
                            "properties" : {
                            "x": { "$ref": "#/definitions/uint" },
                                "y" : { "$ref": "#/definitions/uint" }
                        },
                            "required" : ["x", "y"] ,
                            "additionalProperties" : false
                    },

                        "geometry": {

                            "point": {
                                "type": "object",
                                    "properties" : {
                                    "id":       { "$ref": "#/definitions/uint" },
                                        "name" : { "type": "string" },
                                        "position" : { "$ref": "#/definitions/float3" }
                                },
                                    "required" : ["id", "position"] ,
                                    "additionalProperties" : false
                            },

                                "pointRef": {
                                    "type": "object",
                                        "properties" : {
                                        "id": { "$ref": "#/definitions/uint" }
                                    },
                                        "required" : ["id"] ,
                                        "additionalProperties" : false
                                },

                                    "controlPoints":    {
                                        "type": "array",
                                            "items" : { "$ref": "#/definitions/geometry/pointRef" }
                                    },

                                        "torus" : {
                                        "type": "object",
                                            "properties" : {
                                            "objectType":   { "const": "torus" },
                                                "id" : { "$ref": "#/definitions/uint" },
                                                "name" : { "type": "string" },
                                                "position" : { "$ref": "#/definitions/float3" },
                                                "rotation" : { "$ref": "#/definitions/float3" },
                                                "scale" : { "$ref": "#/definitions/float3" },
                                                "samples" : { "$ref": "#/definitions/uint2" }
                                        },
                                            "required": ["objectType", "id", "position", "rotation", "scale", "samples"] ,
                                            "additionalProperties" : false
                                    },

                                        "bezierC0": {
                                            "type": "object",
                                                "properties" : {
                                                "objectType":       { "const": "bezierC0" },
                                                    "id" : { "$ref": "#/definitions/uint" },
                                                    "name" : { "type": "string" },
                                                    "controlPoints" : { "$ref": "#/definitions/geometry/controlPoints" }
                                            },
                                                "required": ["objectType", "id", "controlPoints"] ,
                                                "additionalProperties" : false
                                        },

                                            "bezierC2": {
                                                "type": "object",
                                                    "properties" : {
                                                    "objectType":       { "const": "bezierC2" },
                                                        "id" : { "$ref": "#/definitions/uint" },
                                                        "name" : { "type": "string" },
                                                        "deBoorPoints" : { "$ref": "#/definitions/geometry/controlPoints" }
                                                },
                                                    "required": ["objectType", "id", "deBoorPoints"] ,
                                                    "additionalProperties" : false
                                            },

                                                "interpolatedC2": {
                                                    "type": "object",
                                                        "properties" : {
                                                        "objectType":       { "const": "interpolatedC2" },
                                                            "id" : { "$ref": "#/definitions/uint" },
                                                            "name" : { "type": "string" },
                                                            "controlPoints" : { "$ref": "#/definitions/geometry/controlPoints" }
                                                    },
                                                        "required": ["objectType", "id", "controlPoints"] ,
                                                        "additionalProperties" : false
                                                }
                        }
}
}
)";
