package com.yeolabgt.mahmoodms.blepharospasmdemo

import android.annotation.SuppressLint
import android.app.Activity
import android.os.Bundle
import kotlinx.android.synthetic.main.classification_summary.*

class ClassificationSummaryActivity : Activity() {
    @SuppressLint("SetTextI18n")
    public override fun onCreate(savedInstanceState:Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.classification_summary)
        val intent = intent
        val requestedDataString = "Summary:" + intent.extras.getString("blepharospasm_diagnosis")
        //TODO: SET TEXT STRING.
        bleph_summary.text = requestedDataString
        bleph_summary.textSize = 22.0f
    }
}

