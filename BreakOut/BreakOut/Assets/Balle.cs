using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Balle : MonoBehaviour {

    private Rigidbody2D rb2d;
    public GameObject paddle;

    // Use this for initialization
    void Start () {
        rb2d = GetComponent<Rigidbody2D>();
        Invoke("GoBall", 2);
    }
	
	// Update is called once per frame
	void Update () {
        if (rb2d.transform.position.y <= paddle.transform.position.y - 1 || rb2d.transform.position.y >= 8 || rb2d.transform.position.x <= -9 || rb2d.transform.position.y >= 9)
            RestartGame();
	}
    void GoBall()
    {
        float rand = Random.Range(0, 2);
        if (rand < 1)
        {
            rb2d.AddForce(new Vector2(20, 30));
        }
        else
        {
            rb2d.AddForce(new Vector2(-20, 30));
        }
    }
    void ResetBall()
    {
        rb2d.velocity = Vector2.zero;
        transform.position = new Vector2(paddle.transform.position.x, paddle.transform.position.y + 0.1f);
    }
    void RestartGame()
    {
        ResetBall();
        Invoke("GoBall", 0);
    }

    void OnCollisionEnter2D(Collision2D coll)
    {
        if (coll.gameObject.tag == "Brick")
        {
            Destroy(coll.gameObject);
        }
        else if (coll.gameObject.tag == "Player")
        {
            Vector2 vel;
            vel.x = (rb2d.velocity.x / 2) + (coll.collider.attachedRigidbody.velocity.x / 3);
            vel.y = rb2d.velocity.y;
            rb2d.velocity = vel;
        }
    }


}
