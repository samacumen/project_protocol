/* AUTO-GENERATED FILE.  DO NOT MODIFY.
 *
 * This class was automatically generated by the
 * java mavlink generator tool. It should not be modified by hand.
 */

// MESSAGE ADAP_TUNING PACKING
package com.MAVLink.ardupilotmega;
import com.MAVLink.MAVLinkPacket;
import com.MAVLink.Messages.MAVLinkMessage;
import com.MAVLink.Messages.MAVLinkPayload;
        
/**
* Adaptive Controller tuning information
*/
public class msg_adap_tuning extends MAVLinkMessage{

    public static final int MAVLINK_MSG_ID_ADAP_TUNING = 11010;
    public static final int MAVLINK_MSG_LENGTH = 49;
    private static final long serialVersionUID = MAVLINK_MSG_ID_ADAP_TUNING;


      
    /**
    * desired rate (degrees/s)
    */
    public float desired;
      
    /**
    * achieved rate (degrees/s)
    */
    public float achieved;
      
    /**
    * error between model and vehicle
    */
    public float error;
      
    /**
    * theta estimated state predictor
    */
    public float theta;
      
    /**
    * omega estimated state predictor
    */
    public float omega;
      
    /**
    * sigma estimated state predictor
    */
    public float sigma;
      
    /**
    * theta derivative
    */
    public float theta_dot;
      
    /**
    * omega derivative
    */
    public float omega_dot;
      
    /**
    * sigma derivative
    */
    public float sigma_dot;
      
    /**
    * projection operator value
    */
    public float f;
      
    /**
    * projection operator derivative
    */
    public float f_dot;
      
    /**
    * u adaptive controlled output command
    */
    public float u;
      
    /**
    * axis
    */
    public short axis;
    

    /**
    * Generates the payload for a mavlink message for a message of this type
    * @return
    */
    public MAVLinkPacket pack(){
        MAVLinkPacket packet = new MAVLinkPacket(MAVLINK_MSG_LENGTH);
        packet.sysid = 255;
        packet.compid = 190;
        packet.msgid = MAVLINK_MSG_ID_ADAP_TUNING;
              
        packet.payload.putFloat(desired);
              
        packet.payload.putFloat(achieved);
              
        packet.payload.putFloat(error);
              
        packet.payload.putFloat(theta);
              
        packet.payload.putFloat(omega);
              
        packet.payload.putFloat(sigma);
              
        packet.payload.putFloat(theta_dot);
              
        packet.payload.putFloat(omega_dot);
              
        packet.payload.putFloat(sigma_dot);
              
        packet.payload.putFloat(f);
              
        packet.payload.putFloat(f_dot);
              
        packet.payload.putFloat(u);
              
        packet.payload.putUnsignedByte(axis);
        
        return packet;
    }

    /**
    * Decode a adap_tuning message into this class fields
    *
    * @param payload The message to decode
    */
    public void unpack(MAVLinkPayload payload) {
        payload.resetIndex();
              
        this.desired = payload.getFloat();
              
        this.achieved = payload.getFloat();
              
        this.error = payload.getFloat();
              
        this.theta = payload.getFloat();
              
        this.omega = payload.getFloat();
              
        this.sigma = payload.getFloat();
              
        this.theta_dot = payload.getFloat();
              
        this.omega_dot = payload.getFloat();
              
        this.sigma_dot = payload.getFloat();
              
        this.f = payload.getFloat();
              
        this.f_dot = payload.getFloat();
              
        this.u = payload.getFloat();
              
        this.axis = payload.getUnsignedByte();
        
    }

    /**
    * Constructor for a new message, just initializes the msgid
    */
    public msg_adap_tuning(){
        msgid = MAVLINK_MSG_ID_ADAP_TUNING;
    }

    /**
    * Constructor for a new message, initializes the message with the payload
    * from a mavlink packet
    *
    */
    public msg_adap_tuning(MAVLinkPacket mavLinkPacket){
        this.sysid = mavLinkPacket.sysid;
        this.compid = mavLinkPacket.compid;
        this.msgid = MAVLINK_MSG_ID_ADAP_TUNING;
        unpack(mavLinkPacket.payload);        
    }

                              
    /**
    * Returns a string with the MSG name and data
    */
    public String toString(){
        return "MAVLINK_MSG_ID_ADAP_TUNING -"+" desired:"+desired+" achieved:"+achieved+" error:"+error+" theta:"+theta+" omega:"+omega+" sigma:"+sigma+" theta_dot:"+theta_dot+" omega_dot:"+omega_dot+" sigma_dot:"+sigma_dot+" f:"+f+" f_dot:"+f_dot+" u:"+u+" axis:"+axis+"";
    }
}
        