using System;
using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using UnityEngine;

public class move : MonoBehaviour {

    public KeyCode moveLeft = KeyCode.LeftArrow;
    public KeyCode moveRight = KeyCode.RightArrow;
    public float speed = 10f;
    public float boundX = 7f;
    private Rigidbody2D rb2d;
    private SerialPort stream = new SerialPort("COM6", 9600);

    // Use this for initialization
    void Start () {
        rb2d = GetComponent<Rigidbody2D>();
        stream.Open();
        stream.ReadTimeout = 1;
    }

    // Update is called once per frame
    void Update () {
        var vel = rb2d.velocity;
        vel.x = 0;
        string value;

        try
        {
            value = stream.ReadLine();
            Debug.Log(value);
            if (value == "RIGHT")
            {
                vel.x = speed;
            }
            else if (value == "LEFT")
            {
                vel.x = -speed;
            }
            rb2d.velocity = vel;
        }

        catch (TimeoutException e)
        {

        }


        var pos = transform.position;
        if (pos.x > boundX)
        {
            pos.x = boundX;
        }

        else if (pos.x < -boundX)
        {
            pos.x = -boundX;
        }
        transform.position = pos;
    }   
}
